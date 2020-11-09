#ifndef DRIEHOEK_H
#define DRIEHOEK_H
#include <QtGui>
#include "punt.h"
#include "schaal.h"
#include <cmath>

#include <iostream>

#define RMIN 0
#define RMAX 255
#define GMIN 0
#define GMAX 255
#define BMIN 0
#define BMAX 255

class driehoek {
private:
  punt *p1;
  punt *p2;
  punt *p3;
  
  schaal *s;
  
  bool geklikt;
  
public:
  driehoek(punt *punt1, punt *punt2, punt *punt3);
  ~driehoek();
  void toon(int d);
  void setSchaal(schaal *sch);
  double area(punt *p1, punt *p2, punt *p3);
  bool puntBinnenDriehoek(int x, int y);
  void setGeklikt(bool klik);
  void teken(QPainter *p);
};

#endif
