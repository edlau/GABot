
#ifndef GAME_H
#define GAME_H

#include <qobject.h>
#include "coordinate.h"

class Team;
class Bot;
class GARule;
class Ball;

/// Game class: perform game playing by assigning bot and ball positions and
/// then using each bot's ruleset to determine its moves
class Game : public QObject {

Q_OBJECT

   public:
      /// two teams, game length, and board size (width, height)
      Game(QObject *parent,Team*, Team*, unsigned int, unsigned int, unsigned int);
      /// destruct 1-1-A-2-B
      ~Game();
      /// perform one turn
      void turn();                     
      /// true if this game is over
      bool over();
      /// reset ball and bots to start positions (at start, after goal)
      void reset();

   private:
      /// determine a Bot's state; also need its team
      GARule* botState(Bot*, unsigned int teamnum);
      /// determine and resolve bots colliding with things
      void botCollision(Bot*, unsigned int teamnum);
      /// determine an index into a sensor array given two coordinates
      unsigned int posIndex(Coordinate, Coordinate);
      /// determine if the ball is in the net and allocate 
	  /// goals to the proper team and player
      unsigned int ballInNet();        
      /// when bots collide, choose which one keeps the ball
      bool tradeBall(Bot*, Bot*, unsigned int, unsigned int);
      /// Pointer to first team
      Team *T1;
	  /// Pointer to second team
	  Team *T2;                   
	  /// Length of game in turns
      unsigned int GameLength;
	  /// Number of turns so far
      unsigned int Turns;
	  /// Board width
      unsigned int Width;
	  /// Board height
	  unsigned int Height;
	  /// Start of net location (calculated from height)
      unsigned int NetStart;
	  /// End of net location (calculated from height)
      unsigned int NetEnd;
	  /// Pointer to the ball
      Ball *B;

   protected slots:
	  /// Activated by the ball emitting a location signal
      void slotBallMoved(Coordinate,Coordinate);

   signals:
	  /// emitted when the ball changes locations
      void ballMoved(Coordinate,Coordinate);
	  /// emitted when team A scores
      void teamAScores(void);
	  /// emitted when team B scores
      void teamBScores(void);
	  /// emitted when the field should be cleared
      void clearField(void);
	  /// emitted at the end of a game
      void gameOver(void);

};

#endif
