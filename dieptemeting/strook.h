#ifndef STROOK_H
#define STROOK_H
#include <QtGui>
#include "driehoek.h"
#include "schaal.h"

#include <iostream>
#include <vector>

using namespace std;

class strook 
{
private:
  vector<driehoek*> driehoeken;
public:
  strook();
  ~strook();
  void toon(int d);
  void voegDriehoekBij(driehoek *d);
  void setSchaal(schaal *s);
  void teken(QPainter *p);
  driehoek *getDriehoek(int nr);
  int getSize();
};

#endif
