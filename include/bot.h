/********************************************************************
 * -= C++ =-
 *
 * Bot class
 *
 ********************************************************************/

#ifndef BOT_H
#define BOT_H

#include "coordinate.h"
#include "direction.h"
#include "garule.h"
#include "ball.h"
#include <qlist.h>
#include <qobject.h>

using namespace BotRotation;

/// Bot class
class Bot : public QObject {

Q_OBJECT

   public:
      /// Constructor
      Bot(QObject *parent=0, const char *name=0);
      /// Constructor
      Bot(QObject *parent, unsigned int mass);
      /// Destructor
      ~Bot();
      
      // methods that affect bot state
      /// Return Mass
      unsigned int mass();
      /// Set Mass
      unsigned int mass(unsigned int);
      /// Return Position
      Coordinate position();
      /// Set Position
      Coordinate position(Coordinate);
      /// Return Direction
      Direction direction();
      /// Set Direction
      Direction direction(Direction);
      /// Return RuleSetSize
      unsigned int ruleSetSize();
      /// Return Ticks
      unsigned int ticksUntilNextMove();
      /// Set Ticks
      unsigned int ticksUntilNextMove(unsigned int);
      /// Execute Rule
      void execRule(GARule*, Ball*, unsigned int, unsigned int);
      /// Return myBall
      bool myBall();
      /// Set myBall
      bool myBall(bool);
      
      // methods to modify or inspect the bot's rules
      /// Get all Rules
      QList<GARule> rules();
      /// Get / Set all Rules
      QList<GARule> rules(QList<GARule>);
      /// Get Rule with specific number
      GARule* rule(unsigned int);
      /// Remove specific Rule
      GARule* removeRule(unsigned int);
      /// Remove the given Rule
      GARule* removeRule(GARule*);
      /// Add the given Rule in position number
      GARule* insertRule(GARule*, unsigned int);
      /// Add the given Rule at the end of the list
      GARule* insertRule(GARule*);
      /// Return the best rule given a rule of conditions
      GARule* bestRule(GARule*);
      /// Generate a random Bot with a given number of rules and mass
      void randomBot(unsigned int, unsigned int);
      /// Mutate a rule chosen at random
      void mutateBot();
      
      // methods to access stats
      /// Get number of goals scored by this bot
      int goals();
      /// Get / Set goals
      int goals(int);
      /// Get Weight to give goals
      static float goalsWeight();
      /// Get / Set weight to give goals
      static float goalsWeight(float);
      /// Get number of interceptions by this bot
      unsigned int interceptions();
      /// Get / Set interceptions
      unsigned int interceptions(unsigned int);
      /// Get Weight to give interceptions
      static float interceptionsWeight();
      /// Get / Set weight to give interceptions
      static float interceptionsWeight(float);
      /// Get time with ball
      unsigned int timeWithBall();
      /// Get / Set time with ball
      unsigned int timeWithBall(unsigned int);
      /// Get Weight to time with ball
      static float timeWithBallWeight();
      /// Get / Set Weight to time with Ball
      static float timeWithBallWeight(float);
      /// Compute this bot's fitness based upon stats
      float fitnessFunction();
      
   private:
      /// Mass of the bot
      unsigned int Mass;
      /// Position of the bot
      Coordinate Pos;
      /// Direction facing of the bot
      Direction Dir;
      /// List of Rules
      QList<GARule> Rules;
      
      // bot stats
      /// Goasl scored by this bot
      unsigned int Goals;
      /// Weight to give goals in fitness function
      static float GoalsWeight;
      /// Interceptions made by this bot
      unsigned int Interceptions;
      /// Weight to give interceptions
      static float InterceptionsWeight;
      /// Number of moves this bot carried the ball
      unsigned int TimeWithBall;
      /// Weight to give moves
      static float TimeWithBallWeight;
      /// Wait states
      unsigned int TicksUntilNextMove;
      /// True if this bot has the ball
      bool MyBall;
      /// An identifying integer
      int BotID;

   signals:
      /// Indicate the bot has moved
      void botMove(Coordinate,Coordinate);
      /// Indicate the bot has changed direction
      void botDirection(Coordinate,Direction);
};

#endif
