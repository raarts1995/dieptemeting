#include "punt.h"

using namespace std;

punt::punt(double px, double py, double pz) {
  x = px;
  y = py;
  z = pz;
}

punt::~punt() {
}

void punt::toon(int d) {
  insprong::springIn(d);
  cout <<"x: " << x << ", y: "<< y <<", z: " << z << "\n";
}

double punt::getX() {
  return x;
}

double punt::getY() {
  return y;
}

double punt::getZ() {
  return z;
}
