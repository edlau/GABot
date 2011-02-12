/********************************************************************
 * -= C++ =-
 *
 * Bot class
 *
 ********************************************************************/

#include "bot.h"
#include "garule.h"
#include "ball.h"
#include "random.h"
#include <cstdlib>
#include <qlist.h>

Bot::Bot(QObject *parent, const char *name)
	:QObject(parent,name) {
   Mass = 5; Pos.x = 0; Pos.y = 0;
   Dir = N;
   MyBall = false;
   Rules.clear();
   Goals = Interceptions = TimeWithBall = 0;
   TicksUntilNextMove = 1;  // will move anon
   BotID = 0;
}

Bot::Bot(QObject *parent, unsigned int m)
	: QObject(parent,0) {
   Mass = m; Pos.x = 0; Pos.y = 0;
   Dir = N;
   MyBall = false;
   Rules.clear();
   Goals = Interceptions = TimeWithBall = 0;
   TicksUntilNextMove = 1;  // will move anon
   BotID = 0;
}

Bot::~Bot(){
   Rules.clear();
}

// init static vars
float Bot::GoalsWeight = 1.0;
float Bot::InterceptionsWeight = 0.5;
float Bot::TimeWithBallWeight = 0.2;

unsigned int Bot::mass() {
   return(Mass);
}

unsigned int Bot::mass(unsigned int m) {
   Mass = m;
   return(Mass);
}

Coordinate Bot::position() {
   return(Pos);
}

Coordinate Bot::position(Coordinate c) {
   if ( (Pos.x != c.x) || (Pos.y != c.y) ) {
      emit(botMove(Pos,c));
      Pos.x = c.x; Pos.y = c.y;
   }
   return(Pos);
}

Direction Bot::direction() {
   return(Dir);
}

Direction Bot::direction(Direction d) {
   if (Dir != d) {
      emit(botDirection(Pos,d));
      Dir = d;
   }
   return(Dir);
}

unsigned int Bot::ruleSetSize() {
   return(Rules.count());
}

unsigned int Bot::ticksUntilNextMove() {
   return(TicksUntilNextMove);
}

unsigned int Bot::ticksUntilNextMove(unsigned int t) {
   TicksUntilNextMove = t;
   return(TicksUntilNextMove);
}

bool Bot::myBall() {
   return(MyBall);
}

bool Bot::myBall(bool b) {
   MyBall = b;
   return(MyBall);
}

QList<GARule> Bot::rules() {
   return(Rules);
}

QList<GARule> Bot::rules(QList<GARule> rs) {
   Rules = rs;
   return(Rules);
}

GARule* Bot::rule(unsigned int num) {
   return Rules.at(num);
}

GARule* Bot::removeRule(unsigned int num) {
   GARule *p = Rules.at(num);
   Rules.remove();
   return p;
}

GARule* Bot::removeRule(GARule *r) {
   Rules.remove(r);
   return r;
}

GARule* Bot::insertRule(GARule *r, unsigned int num) {
   insertChild(r);
   Rules.insert(num, r);
   return r;
}

GARule* Bot::insertRule(GARule *r) {
   insertChild(r);
   Rules.append(r);
   return r;
}

int Bot::goals() {
   return(Goals);
}

int Bot::goals(int g) {
   Goals = g;
   return(Goals);
}

unsigned int Bot::interceptions() {
   return(Interceptions);
}

unsigned int Bot::interceptions(unsigned int i) {
   Interceptions = i;
   return(Interceptions);
}

unsigned int Bot::timeWithBall() {
   return(TimeWithBall);
}

unsigned int Bot::timeWithBall(unsigned int t) {
   TimeWithBall = t;
   return(TimeWithBall);
}

float Bot::goalsWeight() {
   return(GoalsWeight);
}

float Bot::goalsWeight(float w) {
   GoalsWeight = w;
   return(GoalsWeight);
}

float Bot::interceptionsWeight() {
   return(InterceptionsWeight);
}

float Bot::interceptionsWeight(float w) {
   InterceptionsWeight = w;
   return(InterceptionsWeight);
}

float Bot::timeWithBallWeight() {
   return(TimeWithBallWeight);
}

float Bot::timeWithBallWeight(float w) {
   TimeWithBallWeight = w;
   return(TimeWithBallWeight);
}

float Bot::fitnessFunction() {
   float fitness;
   
   fitness = GoalsWeight*Goals +
             InterceptionsWeight*Interceptions +
             TimeWithBallWeight*TimeWithBall;
   
   return(fitness);
}

GARule* Bot::bestRule(GARule *cond) {
   unsigned int *diff;                 // list of differences
   QList<GARule> r;                    // list of rules
   GARule *match;                      // chosen rule
   unsigned int numrules;              // number of rules this bot has
   unsigned int minimum;               // minimum diff between rules
   unsigned int *matches;              // list of indices of matching rules
   unsigned int nummatch;              // number of matches
   unsigned int i;                     // counter
   
   // initialize vars
   numrules = ruleSetSize();
   r = rules();
   diff = new unsigned int[numrules];
   matches = new unsigned int[numrules];
   
   // load the differences and find the minimum
   diff[0] = (r.at(0))->difference(cond);    // get first difference and
   minimum = diff[0];                  // call it the minimum
   for (i=1; i<numrules; i++) {
      diff[i] = (r.at(i))->difference(cond);
      if ( diff[i] < minimum ) {       // this one is smaller
         minimum = diff[i];            // so replace the min
      }
   }
   
   // find how many minima there are and where they live
   nummatch = 0;
   for (i=0; i<numrules; i++) {
      if ( diff[i] == minimum ) {
         matches[nummatch++] = i;
      }
   }
   
   // return one at random
   // pick an int from 0 to nummatch-1
   i = Random::randint(0, nummatch-1);
   match = r.at(matches[i]);
   
   // clear some memory
   delete matches;
   delete diff;
   
   return(match);
}

void Bot::execRule(GARule *r, Ball *B, unsigned int ArenaWidth, unsigned int ArenaHeight) {
   Coordinate pos;
   Direction dir, newdir;
   if (r->fire() && myBall()) {
      // fire the ball in the direction the bot is facing
      myBall(false);
      B->speed(mass());
      B->direction(direction());
      B->moveBall(ArenaWidth, ArenaHeight);    // move ball away from bot
      B->ticksUntilNextMove(1);                // ball will move immediately
   } else if (r->move()) {
      // move in the direction being faced
      pos = position();
      switch (direction()) {
         case N:
            pos.y--;
            break;
         case NE:
            pos.y--; pos.x++;
            break;
         case E:
            pos.x++;
            break;
         case SE:
            pos.y++; pos.x++;
            break;
         case S:
            pos.y++;
            break;
         case SW:
            pos.y++; pos.x--;
            break;
         case W:
            pos.x--;
            break;
         case NW:
            pos.y--; pos.x--;
            break;
      }
      if (pos.x < 0) pos.x = 0;
      if (pos.y < 0) pos.y = 0;
      if (pos.x >= ArenaWidth) pos.x = ArenaWidth - 1;
      if (pos.y >= ArenaHeight) pos.y = ArenaHeight - 1;
      position(pos);
      if (myBall()) B->position(pos);  // also move the ball if the player's holding it
   } else if (r->turn() != BotRotation::None) {
      if (r->turn() == BotRotation::Right) {
         switch(dir) {
            case N:
               newdir = NE;
               break;
            case NE:
               newdir = E;
               break;
            case E:
               newdir = SE;
               break;
            case SE:
               newdir = S;
               break;
            case S:
               newdir = SW;
               break;
            case SW:
               newdir = W;
               break;
            case W:
               newdir = NW;
               break;
            case NW:
               newdir = N;
               break;
         }
      } else {
         switch(dir) {
            case N:
               newdir = NW;
               break;
            case NE:
               newdir = N;
               break;
            case E:
               newdir = NE;
               break;
            case SE:
               newdir = E;
               break;
            case S:
               newdir = SE;
               break;
            case SW:
               newdir = S;
               break;
            case W:
               newdir = SW;
               break;
            case NW:
               newdir = W;
               break;
         }
      }
      direction(newdir);
      if (myBall()) B->direction(newdir);  // also rotate the ball if the player's holding it
   }
   if (myBall()) timeWithBall(timeWithBall()+1);  // increment the time with the ball if it's being held
}

void Bot::randomBot(unsigned int numrules, unsigned int m) {
   
   mass(m);
   for (unsigned int i=0; i<numrules; i++) {
      GARule *NewRule = new GARule;
      NewRule->randomRule();
      insertRule(NewRule);
   }
}

void Bot::mutateBot() {
   unsigned int rulenum = Random::randint(1, ruleSetSize()); rulenum--;
   GARule *r;
   
   r = rule(rulenum);
   r->mutateRule();
}
