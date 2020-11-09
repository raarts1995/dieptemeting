#ifndef SCHAAL_H
#define SCHAAL_H
#include "insprong.h"

class schaal {
public:
  //offset, scale
  double xo, yo, xs, ys;
  double zmin, zmax;
  
  schaal(double xOffset, double yOffset, double xScale, double yScale, double zMin, double zMax);
  void toon(int d);
};

#endif