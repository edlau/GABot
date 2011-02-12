/********************************************************************
 * -= C++ =-
 *  
 * Genetic Algorithm Rule
 *
 ********************************************************************/

#include "garule.h"
#include "thing.h"
#include "random.h"
#include <cstdlib>

GARule::GARule(QObject *parent,const char *name):QObject(parent,name) {
   // makes dumbot rule that just stands there
   TeamBall = 0;
   MyBall = false;
   for (int i = 0; i < 8; i++){
      Sensors[i] = Nothing;
   }
   Fire = false;
   Move = false;
   Turn = None;
}

GARule::~GARule() {
}

GARule::GARule(const GARule& t){

   TeamBall = t.TeamBall;
   MyBall = t.MyBall;
   for (int i = 0; i < 8 ;i++){
      Sensors[i] = t.Sensors[i];
   }
   Fire = t.Fire;
   Move = t.Move;
   Turn = t.Turn;

}

//copy assignment
GARule& GARule::operator=(const GARule& t){

   if(this != &t){
      TeamBall = t.TeamBall;
      MyBall = t.MyBall;
      for (int i = 0; i < 8; i++){
         Sensors[i] = t.Sensors[i];
      }
      Fire = t.Fire;
      Move = t.Move;
      Turn = t.Turn;
   }
   return *this;	
}


int GARule::teamBall(){
   return(TeamBall);
}

bool GARule::myBall(){
   return(MyBall);
}

Thing* GARule::sensors(){
   return(Sensors);
}

bool GARule::fire(){
   return(Fire);
}

bool GARule::move(){
   return(Move);
}

Rotation GARule::turn(){
   return(Turn);
}

int GARule::teamBall(int t){
   TeamBall = t;
   return(TeamBall);
}

bool GARule::myBall(bool b){
   MyBall = b;
   return(MyBall);
}

Thing* GARule::sensors(Thing s[]){
   for (int i = 0; i < 8; i++){
      Sensors[i] = s[i];
   }
   return(Sensors);
}

bool GARule::fire(bool f){
   Fire = f;
   return(Fire);
}

bool GARule::move(bool m){
   Move = m;
   return(Move);
}

Rotation GARule::turn(Rotation t){
   Turn = t;
   return(Turn);
}

unsigned int GARule::difference(GARule *cond) {
   unsigned int diff;
   Thing *condSensors, *mySensors;
   
   diff = 0;                           // initialize difference
   
   if ( abs(cond->teamBall() - teamBall()) > 1 ) {  // one is +ve, one is -ve
      // above line only works if valid values for TeamBall are -1, 0, and 1
      diff += 2;                       // opposite conditions, give it a +2
   } else if ( abs(cond->teamBall() - teamBall()) == 1 ) {  // one is zero, other is not
      // same, only works if TeamBall is one of -1, 0, or 1
      diff += 1;                       // close conditions, give it a +1
   }
   
   if ( cond->myBall() != myBall() ) {  // not the same, this is bad
      diff += 10;                      // weighed more than the rest, since having the
   }                                   // ball is a lot different than not having it
   
   condSensors = cond->sensors();
   mySensors = sensors();
   for (unsigned int i=0; i<8; i++) {
      if ( condSensors[i] != mySensors[i] ) {
         diff++;                       // increment for each differing sensor
      }
   }
   
   return(diff);
}

void GARule::randomRule() {
   int rInt;                           // random integer in case we need it more than once
   int j;                              // variable for scratch use
   
   j = teamBall(Random::randint(-1,1));
   if (j == 1) myBall(Random::randbool());     // have at least some logic in the random rules;
   else myBall(false);                 // if my team doesn't have the ball, then I can't have it

   Thing sens[8];
   for (int i = 0; i < 8; i++){
      rInt = Random::randint(0,5);
      switch(rInt){

         case(0):
	      sens[i] = Nothing;
	      break;
         case(1):
	      sens[i] = MyBot;
	      break;
         case(2):
	      sens[i] = OtherBot;
	      break;
         case(3):
	      sens[i] = TheBall;
	      break;
         case(4):
	      sens[i] = Net;
	      break;
         case(5):
	      sens[i] = Wall;
	      break;

      }//end switch
   }//end for
   sensors(sens);
   fire(Random::randbool());
   move(Random::randbool());
   rInt = Random::randint(0,2);

   if (rInt == 0)      turn(BotRotation::Left);
   else if (rInt == 1) turn(BotRotation::Right);
   else                turn(BotRotation::None);
   // generates rules with more than one action, but should work anyway since
   // only one action will occur
}

void GARule::mutateRule() {
   int rule = Random::randint(0,12);
   int rInt, j;
   
   if (rule < 8) {  // modify the sensor array
      rInt = Random::randint(0,5);
      Thing *sensold, sens[8];
      sensold = sensors();
      for (j=0; j<8; j++) sens[j] = sensold[j];
	  sensold = 0;
      switch(rInt){
         case(0):
	      sens[rule] = Nothing;
	      break;
         case(1):
	      sens[rule] = MyBot;
	      break;
         case(2):
	      sens[rule] = OtherBot;
	      break;
         case(3):
	      sens[rule] = TheBall;
	      break;
         case(4):
	      sens[rule] = Net;
	      break;
         case(5):
	      sens[rule] = Wall;
	      break;
      }
      sensors(sens);
   } else {
      switch(rule) {
         case 8:  // teamBall
            j = teamBall(Random::randint(-1,1));
         case 9:  // myBall
            j = teamBall();
            if (j == 1) myBall(!myBall());
            break;
         case 10: // fire
            fire(!fire());
            break;
         case 11: // move
            move(!move());
            break;
         case 12: // turn
            rInt = Random::randint(0,2);
            if (rInt == 0)      turn(BotRotation::Left);
            else if (rInt == 1) turn(BotRotation::Right);
            else                turn(BotRotation::None);
            break;
      }
   }
}
