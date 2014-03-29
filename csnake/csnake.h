#ifndef CSNAKE_H
#define CSNAKE_H

// for the cordinates of the points
typedef struct _point {
  int x;
  int y;
} Point;

// four corner point
typedef enum _CornerCoord {
  topLeft,
  topRight,
  bottomRight,
  bottomLeft
} CornerCord;


#endif
