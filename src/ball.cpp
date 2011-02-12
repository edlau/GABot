/********************************************************************
 * -= C++ =-
 * Ball class
 ********************************************************************/

#include "ball.h"
#include "coordinate.h"
#include "direction.h"

//-----------------------------------------------------
Ball::Ball(QObject *parent, const char * name)
	:QObject(parent,name)
{
   Coordinate p;
   p.x = 0; p.y = 0;
   reset(p);
}
//-----------------------------------------------------
Ball::~Ball() 
{
}
//-----------------------------------------------------
void Ball::reset(Coordinate p) 
{
   Speed = 0;
   Pos.x = p.x; Pos.y = p.y;
   Dir = N;
   Team = 0;
   Player = 0;
   TicksUntilNextMove = 0;
}
//-----------------------------------------------------
unsigned int Ball::speed() 
{
   return(Speed);
}
//-----------------------------------------------------
unsigned int Ball::speed(unsigned int s) 
{
   if (Speed != s) {
      Speed = s;
   }
   return(Speed);
}
//-----------------------------------------------------
Coordinate Ball::position() 
{
   return(Pos);
}
//-----------------------------------------------------
Coordinate Ball::position(Coordinate p) 
{
   if ( (Pos.x != p.x) || (Pos.y != p.y) ) {
      emit(ballMove(Pos, p));
      Pos.x = p.x; Pos.y = p.y;
   }
   return(Pos);
}
//-----------------------------------------------------
Direction Ball::direction() 
{
   return(Dir);
}
//-----------------------------------------------------
Direction Ball::direction(Direction d) 
{
   if (Dir != d) {
      Dir = d;
   }
   return(Dir);
}
//-----------------------------------------------------
unsigned int Ball::team() 
{
   return(Team);
}
//-----------------------------------------------------
unsigned int Ball::team(unsigned int t) 
{
   if (Team != t) {
      Team = t;
   }
   return(Team);
}
//-----------------------------------------------------
unsigned int Ball::player() 
{
   return(Player);
}
//-----------------------------------------------------
unsigned int Ball::player(unsigned int p) 
{
   if (Player != p) {
      Player = p;
   }
   return(Player);
}
//-----------------------------------------------------
unsigned int Ball::ticksUntilNextMove() 
{
   return(TicksUntilNextMove);
}
//-----------------------------------------------------
unsigned int Ball::ticksUntilNextMove(unsigned int t) 
{
   if (TicksUntilNextMove != t) {
      TicksUntilNextMove = t;
   }
   return(TicksUntilNextMove);
}
//-----------------------------------------------------
void Ball::moveBall(unsigned int ArenaWidth, unsigned int ArenaHeight) 
{
   Coordinate pos = position();
   Direction dir = direction();
   Direction newdir = dir;

   switch(dir) {
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
   if ( (pos.y < 0) && (pos.x < 0) && (dir == NW) ) {
      // collided with nw corner
      newdir = SE;
      pos.x = pos.y = 0;
   } else
   if ( (pos.y < 0) && (pos.x >= ArenaWidth) && (dir == NE) ) {
      // collided with ne corner
      newdir = SW;
      pos.y = 0;
      pos.x = ArenaWidth - 1;
   } else
   if ( (pos.y >= ArenaHeight) && (pos.x < 0) && (dir == SW) ) {
      // collided with sw corner
      newdir = NE;
      pos.x = 0;
      pos.y = ArenaHeight - 1;
   } else
   if ( (pos.y >= ArenaHeight) && (pos.x >= ArenaWidth) && (dir == SE) ) {
      // collided with se corner
      newdir = NW;
      pos.x = ArenaWidth - 1;
      pos.y = ArenaHeight - 1;
   } else
   if (pos.y < 0) {
      // collided with north wall
      switch(dir) {
         case N:
            newdir = S;
            break;
         case NE:
            newdir = SE;
            break;
         case NW:
            newdir = SW;
            break;
         // default should not be reached
      }
      pos.y = 0;
   } else
   if (pos.y >= ArenaHeight) {
      // collided with south wall
      switch(dir) {
         case S:
            newdir = N;
            break;
         case SE:
            newdir = NE;
            break;
         case SW:
            newdir = NW;
            break;
         // default should not be reached
      }
      pos.y = ArenaHeight - 1;
   } else
   if (pos.x < 0) {
      // collided with west wall
      switch(dir) {
         case W:
            newdir = E;
            break;
         case NW:
            newdir = NE;
            break;
         case SW:
            newdir = SE;
            break;
         // default should not be reached
      }
      pos.x = 0;
   } else
   if (pos.x >= ArenaWidth) {
      // collided with east wall
      switch(dir) {
         case E:
            newdir = W;
            break;
         case NE:
            newdir = NW;
            break;
         case SE:
            newdir = SW;
            break;
         // default should not be reached
      }
      pos.x = ArenaWidth - 1;
   }
   Coordinate old = position();
   position(pos);
   direction(newdir);
   emit(ballMove(old,pos));
}
//-----------------------------------------------------
