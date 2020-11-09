#include "schaal.h"

using namespace std;

schaal::schaal(double xOffset, double yOffset, double xScale, double yScale, double zMin, double zMax) {
  xo = xOffset;
  yo = yOffset;
  xs = xScale;
  ys = yScale;
  zmin = zMin;
  zmax = zMax;
}

void schaal::toon(int d) {
  insprong::springIn(d);
  cout << "xs: " << xs << ", ys: " << ys << ", xo: " << xo << ", yo: " << yo << ", zmin: " << zmin << ", zmax: " << zmax << "\n";
}