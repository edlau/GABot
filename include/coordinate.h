/********************************************************************
 * -= C++ =-
 *
 * the class for coordinate (x,y)
 *
 ********************************************************************/

#ifndef COORDINATE_H
#define COORDINATE_H

/// Coordinate object
class Coordinate {
   public:
      /// default constructor
      Coordinate() {};
      /// constructor
      Coordinate(int x1, int y1) { x = x1; y = y1; };
      /// direction in x
      int x;
      /// direction in y
      int y;
};

#endif
