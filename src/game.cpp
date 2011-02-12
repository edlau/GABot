/********************************************************************
 * -= C++ =-
 * Game class: perform game playing
 ********************************************************************/

//predirectives
#include "game.h"
#include "team.h"
#include "ball.h"
#include "bot.h"
#include "coordinate.h"
#include "rotation.h"
#include "garule.h"
#include "thing.h"
#include "random.h"
#include <cstdlib>
#include <cmath>

#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi, from glibc 2.2.2 */
#endif

Game::Game(QObject *parent,Team *t1, Team *t2, unsigned int l, unsigned int w, unsigned int h)
	: QObject(parent,0) {


   B = new Ball(this);
   connect (B,SIGNAL(ballMove(Coordinate,Coordinate)),this,SLOT(slotBallMoved(Coordinate,Coordinate)));
   
   T1 = t1; T2 = t2;
   GameLength = l;
   Turns = 0;
   Width = w; Height = h;
   
   NetStart = Height / 3;
   NetEnd = Height - NetStart;
   
   reset();
}

Game::~Game() {
}

void Game::reset() {
   Coordinate pos;

   emit(clearField());

   // initialize bot positions
   unsigned int i, teamsize, rank; double spacing;
   Bot *curbot;
   teamsize = T1->size();
   spacing = 40.0 / (teamsize % 40);    // no more than 40 bots in a rank (will teams be bigger than that? :-)
   for (i=0; i<teamsize; i++) {
      curbot = T1->bot(i);
      rank = (int)((double)i / 40.0 + 0.5);
      pos.x = 35 - 5 * rank;
      pos.y = (int)( (spacing / 2.0) + (i % 40) * spacing + 0.5);
      pos = curbot->position(pos);
      curbot->direction(E);
   }
   teamsize = T2->size();
   spacing = 40.0 / (teamsize % 40);    // no more than 40 bots in a rank (will teams be bigger than that? :-)
   for (i=0; i<teamsize; i++) {
      curbot = T2->bot(i);
      rank = (int)((double)i / 40.0 + 0.5);
      pos.x = 45 + 5 * rank;
      pos.y = (int)( (spacing / 2.0) + (i % 40) * spacing + 0.5);
      pos = curbot->position(pos);
      curbot->direction(W);
   }
   
   // reset the ball
   pos.x = (Width + 1) / 2;
   pos.y = (Height + 1) / 2;
   B->reset(pos);
}

void Game::turn() {
   Bot *curbot;
   unsigned int teamsize;
   unsigned int ticks;
   GARule *state;
   GARule *best;
   
   Turns++;
   if (ballInNet() != 0) {  // check and score goals
      reset();              // start over if a goal was scored
   }

   teamsize = T1->size() > T2->size() ? T1->size() : T2->size();
   for (unsigned int i=0; i<teamsize; i++) { // do both teams at once
      if (i < T1->size()) {            // in case team sizes are different
         curbot = T1->bot(i);
         ticks = curbot->ticksUntilNextMove(curbot->ticksUntilNextMove() - 1);
         if (ticks == 0) {             // this bot's time is up!
            
            // reset ticks
            curbot->ticksUntilNextMove(curbot->mass());
            
            // here's where the state should be programmed into a rule
            state = botState(curbot, 0);
            
            // determine best match
            best = curbot->bestRule(state);
            
            // execute rule
            curbot->execRule(best, B, Width, Height);
            
            // handle collisions
            botCollision(curbot, 0);
            
         }
      }
      if (i < T2->size()) {            // now do it again for bot i on team 2
         curbot = T2->bot(i);
         ticks = curbot->ticksUntilNextMove(curbot->ticksUntilNextMove() - 1);
         if (ticks == 0) {             // this bot's time is up!
            
            // reset ticks
            curbot->ticksUntilNextMove(curbot->mass());
            
            // here's where the state should be programmed into a rule
            state = botState(curbot, 1);
            
            // determine best match
            best = curbot->bestRule(state);
            
            // execute rule
            curbot->execRule(best, B, Width, Height);
            
            // handle and resolve collisions
            botCollision(curbot, 1);
            
         }
      }
   }
   
   // do stuff to ball if it's moving
   if (B->speed() != 0) {
      ticks = B->ticksUntilNextMove(B->ticksUntilNextMove() - 1);
      if (ticks == 0) {
         
         // reset ticks
         B->ticksUntilNextMove(11 - B->speed());  // assumes max speed of 10
         
         // move it
         B->moveBall(Width, Height);
         
      }
   }
   if (Turns >= GameLength) emit(gameOver());
}

bool Game::over() {
   return (Turns >= GameLength);
}

unsigned int Game::posIndex(Coordinate first, Coordinate second) {
   // find angle, rounded to 45 degrees
   double angle = atan2(first.y - second.y, second.x - first.x);  // yeah, that's right
   angle *= 4.0 / M_PI;  // convert to a value from 0 to 4
   unsigned int index;   // now convert to an index into the sensor array
   if (angle < 0) {
      angle = fabs(angle);
      if (angle < 0.5) index = 2;
      else if (angle < 1.5) index = 3;
      else if (angle < 2.5) index = 4;
      else if (angle < 3.5) index = 5;
      else index = 6;
   } else {
      if (angle < 0.5) index = 2;
      else if (angle < 1.5) index = 1;
      else if (angle < 2.5) index = 0;
      else if (angle < 3.5) index = 7;
      else index = 6;
   }
   return index;
}

void Game::botCollision(Bot *b, unsigned int teamnum) {
   Team *myTeam, *otherTeam;
   Bot *curbot;
   Coordinate myPos, theirPos;
   unsigned int myBotNum;
   bool myBall;
   unsigned int i;
   
   if (teamnum == 0) {
      myTeam = T1;
      otherTeam = T2;
   } else {
      myTeam = T2;
      otherTeam = T1;
   }
   
   myPos = b->position();
   myBall = b->myBall();
   
   // handle collisions with my team
   for (i=0; i<myTeam->size(); i++) {
      curbot = myTeam->bot(i);
      if (curbot != b) {
         theirPos = curbot->position();
         if ( (theirPos.x == myPos.x) && (theirPos.y == myPos.y) ) {

            // right now, bots on the same team won't steal the ball
            // bots are courteous and let higher-numbered bots move

            // move back in the opposite direction
            switch (b->direction()) {
               case N:
                  myPos.y++;
                  break;
               case NE:
                  myPos.y++; myPos.x--;
                  break;
               case E:
                  myPos.x--;
                  break;
               case SE:
                  myPos.y--; myPos.x--;
                  break;
               case S:
                  myPos.y--;
                  break;
               case SW:
                  myPos.y--; myPos.x++;
                  break;
               case W:
                  myPos.x++;
                  break;
               case NW:
                  myPos.y++; myPos.x++;
                  break;
            }
            if (myPos.x < 0) myPos.x = 0;  // automagically do wall collisions
            if (myPos.y < 0) myPos.y = 0;
            if (myPos.x >= Width) myPos.x = Width - 1;
            if (myPos.y >= Height) myPos.y = Height - 1;
            b->position(myPos);
            if (b->myBall()) B->position(myPos);  // move ball along with player
         }
      } else myBotNum = i;
   }
   
   // handle collisions with other team
   for (i=0; i<otherTeam->size(); i++) {
      curbot = otherTeam->bot(i);
      theirPos = curbot->position();
      if ( (theirPos.x == myPos.x) && (theirPos.y == myPos.y) ) {
         if (myBall) {
            // see if the ball got traded (stolen)
            if (tradeBall(b, curbot, (teamnum == 0 ? 1 : 0), i)) {
               myBall = false;  // guess I lost it, eh?
            }
         } else if (curbot->myBall()) {
            if (tradeBall(curbot, b, teamnum, myBotNum)) {
               myBall = true;  // woo!
            }
         }
         
         // bots are _really_ courteous and let bots on the other team move

	 // each bot turn right 45 degree to go around

	 switch(b->direction()){
            case N:
		    b->direction(NE);
		    break;
	    case NE:
		    b->direction(E);
		    break;
	    case E:
		    b->direction(SE);
		    break;
	    case SE:
		    b->direction(S);
		    break;
	    case S:
		    b->direction(SW);
		    break;
	    case SW:
		    b->direction(W);
		    break;
	    case W:
		    b->direction(NW);
		    break;
	    case NW:
		    b->direction(N);
		    break;
	 }
	 
         if (myPos.x < 0) myPos.x = 0;  // automagically do wall collisions
         if (myPos.y < 0) myPos.y = 0;
         if (myPos.x >= Width) myPos.x = Width - 1;
         if (myPos.y >= Height) myPos.y = Height - 1;
         b->position(myPos);
         if (b->myBall()) B->position(myPos);  // move ball along with player
      }
   }
   
   // handle collisions with the ball (only considered a collision if the player didn't already have the ball)
   theirPos = B->position();
   if ( (theirPos.x == myPos.x) && (theirPos.y == myPos.y) && (!b->myBall()) ) {
      unsigned int lt = B->team();
      unsigned int lp = B->player();
      if (lt != 0) {  // count an interception if the ball was last touched by another player
         lt--;  // stupid: teamnum is 0 or 1, but lt is 0 to denote a ball that hasn't been touched yet
         if (lt != teamnum) b->interceptions(b->interceptions()+1);
      }
      myBall = b->myBall(true);
      b->timeWithBall(b->timeWithBall()+1);  // increment time with ball
      B->team(teamnum+1);
      B->player(myBotNum);
      B->speed(0);  // move the ball along with the player holding it
   }
   
}

bool Game::tradeBall(Bot *a, Bot *b, unsigned int bTeam, unsigned int bNum) {
   double prob, rnd;
   bool ret = false;
   
   // larger bots have a better chance of getting the ball
   prob = 0.5 - ( (b->mass() - a->mass()) / 20.0 );
   rnd = Random::randd(0,1);
   if (rnd > prob) {  // bot b gets the ball
      a->myBall(false);
      b->myBall(true);
      B->team(bTeam);
      B->player(bNum);
      ret = true;
   }
   return ret;
}

GARule* Game::botState(Bot *b, unsigned int teamnum) {
   Team *myTeam, *otherTeam;
   Bot *curbot;
   unsigned int Range = 5;             // all sensor ranges set to 5
   Coordinate myPos, theirPos;
   GARule *state = new GARule(this);
   unsigned int mySensor[8];           // separate sensors that will be compiled at the end
   unsigned int otherSensor[8];        // these are absolute, they'll be converted to
   unsigned int ballSensor[8];         // relative at the end, based on the dir the bot is facing
   unsigned int netSensor[8];
   unsigned int wallSensor[8];
   unsigned int allSensors[8];
   unsigned int index, distance;       // some useful variables
   unsigned int i, j;                  // useful index variable
   int teamBall = 0;
   bool myBall;
   
   if (teamnum == 0) {
      myTeam = T1;
      otherTeam = T2;
   } else {
      myTeam = T2;
      otherTeam = T1;
   }
   
   // clear all the sensor arrays
   for (i=0; i<8; i++) mySensor[i] = 0;
   for (i=0; i<8; i++) otherSensor[i] = 0;
   for (i=0; i<8; i++) wallSensor[i] = 0;
   for (i=0; i<8; i++) netSensor[i] = 0;
   for (i=0; i<8; i++) ballSensor[i] = 0;
   
   myPos = b->position();
   myBall = b->myBall();
   if (myBall) teamBall = 1;
   
   // scan for bots on my own team
   for (i=0; i<myTeam->size(); i++) {
      curbot = myTeam->bot(i);
      if (curbot != b) {  // not me
         theirPos = curbot->position();
         distance = (unsigned int)sqrt( pow(myPos.x - theirPos.x, 2) +  // compute distance to object
                                        pow(myPos.y - theirPos.y, 2) );
         if ( distance <= Range ) {             // within range, so I can see it
            index = posIndex(myPos, theirPos);  // compute index into sensor array
            mySensor[index] = distance;
         }
      }
      if (curbot->myBall()) teamBall = 1;
   }
   
   // scan for bots on other teams
   for (i=0; i<otherTeam->size(); i++) {
      curbot = otherTeam->bot(i);
      theirPos = curbot->position();
      distance = (unsigned int)sqrt( pow(myPos.x - theirPos.x, 2) +  // compute distance to object
                                     pow(myPos.y - theirPos.y, 2) );
      if (distance <= Range) {
         index = posIndex(myPos, theirPos);
         otherSensor[index] = distance;
      }
      if (curbot->myBall()) teamBall = -1;
   }
   
   // determine if the ball is in range
   theirPos = B->position();
   distance = (unsigned int)sqrt( pow(myPos.x - theirPos.x, 2) +  // compute distance to object
                                  pow(myPos.y - theirPos.y, 2) );
   if (distance <= Range) {
      index = posIndex(myPos, theirPos);
      ballSensor[index] = distance;
   }
   
   // find walls
   if (myPos.y < Range) {  // north wall
      wallSensor[0] = wallSensor[1] = wallSensor[7] = myPos.y + 1;  // since technically the wall's at y=-1
   } else if ( (Height - myPos.y) <= Range) {  // south wall
      wallSensor[3] = wallSensor[4] = wallSensor[5] = Height - myPos.y;
   }
   if (myPos.x < Range) {  // west wall
      wallSensor[5] = wallSensor[6] = wallSensor[7] = myPos.x + 1;
   } else if ( (Width - myPos.x) <= Range) {  // east wall
      wallSensor[1] = wallSensor[2] = wallSensor[3] = Width - myPos.x;
   }
   
   // find net
   if (teamnum == 0) {
      if ( (Width - myPos.x) <= Range) {
         if (myPos.y == NetStart) netSensor[2] = netSensor[3] = Width - myPos.x;
         else if (myPos.y > NetStart) {
            if (myPos.y == NetEnd) netSensor[1] = netSensor[2] = Width - myPos.x;
            else if (myPos.y < NetEnd) netSensor[1] = netSensor[2] = netSensor[3] = Width - myPos.x;
         }
      }
   } else {
      if (myPos.x < Range) {
         if (myPos.y == NetStart) netSensor[2] = netSensor[3] = myPos.x + 1;
         else if (myPos.y > NetStart) {
            if (myPos.y == NetEnd) netSensor[1] = netSensor[2] = myPos.x + 1;
            else if (myPos.y < NetEnd) netSensor[1] = netSensor[2] = netSensor[3] = myPos.x + 1;
         }
      }
   }
   
   // now find the closest object and put that in state
   Thing *sensors = new Thing[8];
   for (i=0; i<8; i++) {
      unsigned int offset;            // offset of index into direction in state
      switch(b->direction()) {
         case N:  offset = 0; break;  // already in right order
         case NE: offset = 7; break;
         case E:  offset = 6; break;
         case SE: offset = 5; break;
         case S:  offset = 4; break;
         case SW: offset = 3; break;
         case W:  offset = 2; break;
         case NW: offset = 1; break;
      }
      index = (i + offset) % 8;
      sensors[index] = Nothing;
      // search for nearest object, and place it in the real sensor array
      allSensors[i] = Range + 1;
      if ( (mySensor[i] > 0) && (mySensor[i] < allSensors[i]) ) {
         allSensors[i] = mySensor[i];
         sensors[index] = MyBot;
      }
      if ( (otherSensor[i] > 0) && (otherSensor[i] < allSensors[i]) ) {
         allSensors[i] = otherSensor[i];
         sensors[index] = OtherBot;
      }
      if ( (ballSensor[i] > 0) && (ballSensor[i] < allSensors[i]) ) {
         allSensors[i] = ballSensor[i];
         sensors[index] = TheBall;
      }
      if ( (netSensor[i] > 0) && (netSensor[i] < allSensors[i]) ) {
         allSensors[i] = netSensor[i];
         sensors[index] = Net;
      }
      if ( (wallSensor[i] > 0) && (wallSensor[i] < allSensors[i]) ) {
         allSensors[i] = wallSensor[i];
         sensors[index] = Wall;
      }
   }
   // at this point, sensors should be ready to stick into the rule
   state->sensors(sensors);
   
   // other stuff should be set, too
   state->teamBall(teamBall);
   state->myBall(myBall);
   
   delete [] sensors;
   // should be ready to go
   return state;
}

void Game::slotBallMoved(Coordinate Old, Coordinate New) {
	emit (ballMoved(Old, New));
}

unsigned int Game::ballInNet() {
   Coordinate pos = B->position();
   Bot *b;
   
   unsigned int ret = 0;
   
   if ( (pos.y >= NetStart) && (pos.y <= NetEnd) ) {
      if (pos.x == 0) {
         // in team A's net, so team B gets the point
         T2->goals(T2->goals() + 1);
         emit(teamBScores());
         ret = 2;
         if (B->team() == 1) {
            // Oh, you suck! You scored on your own net!
            b = T1->bot(B->player());
            b->goals(b->goals() - 1);
         } else if (B->team() == 2) {
            // YAY!
            b = T2->bot(B->player());
            b->goals(b->goals() + 1);
         }
      } else if (pos.x == (Width - 1)) {
         // in team B's net, so team A gets the point
         T1->goals(T1->goals() + 1);
         emit(teamAScores());
         ret = 1;
         if (B->team() == 1) {
            // YAY!
            b = T1->bot(B->player());
            b->goals(b->goals() + 1);
         } else if (B->team() == 2) {
            // Oh, you suck! You scored on your own net!
            b = T2->bot(B->player());
            b->goals(b->goals() - 1);
         }
      }
   }
   return ret;
}
