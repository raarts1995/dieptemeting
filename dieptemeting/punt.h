#ifndef PUNT_H
#define PUNT_H
#include "insprong.h"

#include <iostream>

class punt
{
private:
  double x;
  double y;
  double z;

public:
  punt(double px, double py, double pz);
  ~punt();
  void toon(int d);
  double getX();
  double getY();
  double getZ();
};

#endif
