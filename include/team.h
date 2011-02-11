#ifndef TEAM_H
#define TEAM_H

class Bot;
#include <qlist.h>
#include <qstring.h>
#include <qobject.h>
#include "coordinate.h"
#include "direction.h"

/// Team class: defines a "team" or population of Bots
/// presumably there are two of these at a time, unless we decide to play
/// more than two teams at once
class Team : public QObject {

Q_OBJECT

   public:
      /// Constructor
      Team(QObject *parent=0, const char *name=0);
      /// Destructor
      ~Team();
          /// return size of team
      unsigned int size();
	  /// return a list of bots
      QList<Bot> bots();
	  /// set the list of bots
      QList<Bot> bots(QList<Bot>);
	  /// send bot X back to the minors
      Bot* removeBot(unsigned int X);
	  /// pull a bot up from the minors
      unsigned int insertBot(Bot*);
	  /// pull a bot up from the minors, with number
      unsigned int insertBot(Bot*, unsigned int);
	  /// returns a particular bot, by number
      Bot* bot(unsigned int);
	  /// generate a random team of size X
      void randomTeam(unsigned int X);
	  /// return number of team goals
      int goals();
	  /// set number of team goals
      int goals(int);
	  /// return number of wins
      unsigned int wins();
	  /// set number of wins
      unsigned int wins(unsigned int);
	  /// return number of losses
      unsigned int losses();
	  /// set number of losses
      unsigned int losses(unsigned int);
	  /// return number of ties
      unsigned int ties();
	  /// set number of ties
      unsigned int ties(unsigned int);
	  /// return number of generations
      unsigned int generations();
	  /// set number of generations
      unsigned int generations(unsigned int);
	  /// return team name
      QString name();
	  /// set team name
      QString name(QString);

   private:
      /// ball is ours (+ve), theirs (-ve), or neither (0)
      int TeamBall;
      /// goals scored by this team in its current game
      int Goals;
      /// number of wins by this team
      unsigned int Wins;
      /// number of losses by this team
      unsigned int Losses;
      /// number of ties by this team
      unsigned int Ties;
      /// number of generations
      unsigned int Generations;
      /// Team name
      QString Name;
      /// List of bots
      QList<Bot> Bots;

   protected slots:
      /// Handle Bot movements
      void slotBotMove(Coordinate,Coordinate);
      /// Handle Bot direction changes
      void slotBotDirection(Coordinate,Direction);

   signals:
      /// emitted when a bot has moved
      void botMove(Coordinate,Coordinate);
      /// emitted when a bot has changed direction
      void botDirection(Coordinate,Direction);
};

#endif
