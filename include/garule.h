/********************************************************************
 * -= C++ =-
 *  
 * Genetic Algorithm Rule
 *
 ********************************************************************/

#ifndef GARULE_H
#define GARULE_H

// predirectives
#include "rotation.h"
#include "thing.h"
#include <qobject.h>

/// For bot Rotations
using namespace BotRotation;

/// Main class for the rules in our Genetic Algorithm
class GARule : public QObject{
   public:
      /// Constructor
      GARule(QObject *parent=0,const char *name=0);
      /// Destructor
      ~GARule();
      /// Copy Constructor
      GARule(const GARule&);
      /// Copy Assignment
      GARule& operator=(const GARule&);
      /// Member function to return teamBall
      int teamBall();
      /// Member function to return myBall
      bool myBall();
      /// Member function to return the pointer of the sensor array
      Thing* sensors();
      /// Member function to return fire
      bool fire();
      /// Member function to return move
      bool move();
      /// Member function to return turn
      Rotation turn();
      
      /// Member function to set teamBall
      int teamBall(int);
      /// Member function to set myBall
      bool myBall(bool);
      /// Member function to set the sensors
      Thing* sensors(Thing[]);
      /// Member function to set fire
      bool fire(bool);
      /// Member function to set move
      bool move(bool);
      /// Member function to set rotation
      Rotation turn(Rotation);
      /// Generate a random rule
      void randomRule();
      /// Mutate the rule
      void mutateRule();
      /// Find the difference between the conditions in this rule and the ones in the given rule
      unsigned int difference(GARule*);
      
   private:
      // conditions
      /// Ball is ours (+ve), theirs (-ve), or nither (0)
      int TeamBall;
      /// Ball is in this bot's posessioin
      bool MyBall;
      /// Sensor states
      Thing Sensors[8];
      
      // actions
      /// Fire the ball (shoot or pass, same thing)
      bool Fire;
      /// Move in directions being faced
      bool Move;
      /// Angle to turn by (Left, Right, None)
      Rotation Turn;

};

#endif
