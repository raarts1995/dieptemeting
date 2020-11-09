#ifndef METING_H
#define METING_H
#include "punt.h"
#include "insprong.h"

#include <iostream>
#include <vector>

using namespace std;

class meting {
private:
  vector<punt *> punten; // de lijst met punten
  
public:
  meting();  // constructor
  ~meting(); // deconstructor
  void toon(int d);
  void voegPuntBij(punt *p);
  punt* getPunt(int n);
  int getSize();
};

#endif
