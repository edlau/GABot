#ifndef BALL_H
#define BALL_H

#include <qobject.h>
#include "coordinate.h"
#include "direction.h"

/// Ball class
class Ball : public QObject {

Q_OBJECT

   public:
      /// Constructor
      Ball(QObject *parent=0, const char * name = 0);
      /// Destructor
      ~Ball();
      /// return speed
      unsigned int speed();
      /// return / set speed
      unsigned int speed(unsigned int);
      /// return position
      Coordinate position();
      /// return / set speed
      Coordinate position(Coordinate);
      /// return direction
      Direction direction();
      /// return / set direction
      Direction direction(Direction);
      /// return which team has the ball
      unsigned int team();
      /// return / set which team has the ball
      unsigned int team(unsigned int);
      /// return which player has the ball
      unsigned int player();
      /// return / set which player has the ball
      unsigned int player(unsigned int);
      /// return Ticks
      unsigned int ticksUntilNextMove();
      /// return / set Ticks
      unsigned int ticksUntilNextMove(unsigned int);
      /// move the ball
      void moveBall(unsigned int, unsigned int);
      /// reset position of the ball
      void reset(Coordinate);
      
   private:
      /// whatever maximum speed is (10?) - this
      /// = how many ticks between moves
      /// if 0, then not moving
      unsigned int Speed;              
	  /// (x,y) position on board
      Coordinate Pos;
	  /// direction of movement
      Direction Dir;
	  /// most recent team to have ball (0, 1 or 2)
      unsigned int Team;
	  /// most recent player on team to have ball
      unsigned int Player;
	  /// wait states
      unsigned int TicksUntilNextMove;

   signals:
      /// indicate ball movement
      void ballMove(Coordinate, Coordinate);
};

#endif
