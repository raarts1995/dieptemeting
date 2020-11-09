#include "driehoek.h"

using namespace std;

driehoek::driehoek(punt *punt1, punt *punt2, punt *punt3) {
  p1 = punt1;
  p2 = punt2;
  p3 = punt3;
  geklikt = false;
}

driehoek::~driehoek() {
  delete p1;
  delete p2;
  delete p3;
}

void driehoek::toon(int d) {
  cout << "driehoek\n";
  insprong::springIn(d);
  cout << "p1: ";
  p1->toon(d);
  cout << "p2: ";
  p2->toon(d); 
  cout << "p3: ";
  p3->toon(d);
}

void driehoek::setSchaal(schaal *sch) {
  s = sch;
}
/* A utility function to calculate area of triangle formed by (x1, y1), 
   (x2, y2) and (x3, y3) */
double driehoek::area(punt *p1, punt *p2, punt *p3)
{
   return abs((p1->getX()*(p2->getY()-p3->getY()) + p2->getX()*(p3->getY()-p1->getY())+ p3->getX()*(p1->getY()-p2->getY()))/2.0);
}

bool driehoek::puntBinnenDriehoek(int x, int y) {
  //X-px = ((X-m - s->xo) * s->xs);
  //X-m = X-px / s->xs + s->xo;
  
  punt punt1(((p1->getX() - s->xo) * s->xs), ((p1->getY() - s->yo) * s->ys), 0);
  punt punt2(((p2->getX() - s->xo) * s->xs), ((p2->getY() - s->yo) * s->ys), 0);
  punt punt3(((p3->getX() - s->xo) * s->xs), ((p3->getY() - s->yo) * s->ys), 0);
  punt p(x, y, 0);
  //s->toon(0);
  /*p.toon(0);
  punt1.toon(0);
  punt2.toon(0);
  punt3.toon(0);
  cout << "\n";*/
  
  /* Calculate area of triangle ABC */
  double A = area (&punt1, &punt2, &punt3);

  /* Calculate area of triangle PBC */  
  double A1 = area (&p, &punt2, &punt3);

  /* Calculate area of triangle PAC */  
  double A2 = area (&punt1, &p, &punt3);

  /* Calculate area of triangle PAB */   
  double A3 = area (&punt1, &punt2, &p);
  
  /* Check if sum of A1, A2 and A3 is same as A */
  return (A == A1 + A2 + A3);
}

void driehoek::setGeklikt(bool klik) {
  geklikt = klik;
}

void driehoek::teken(QPainter *p) {
  int x1 = (int)((p1->getX() - s->xo) * s->xs);
  int y1 = (int)((p1->getY() - s->yo) * s->ys);
  int x2 = (int)((p2->getX() - s->xo) * s->xs);
  int y2 = (int)((p2->getY() - s->yo) * s->ys);
  int x3 = (int)((p3->getX() - s->xo) * s->xs);
  int y3 = (int)((p3->getY() - s->yo) * s->ys);
  
  
  // maak een lijst van 3 punten
  QPolygon polygon(3);  
  polygon.putPoints(0, 3, x1,y1, x2,y2, x3,y3);
  
  //bereken de gemiddelde z waarde
  double z = p1->getZ()/3 + p2->getZ()/3 + p3->getZ()/3;
  
  //cout << "gemiddelde z waarde: " << z << "\n";
  
  // stel een kleur in
  double u = (z - s->zmin)/(s->zmax - s->zmin);
  int r = (int)((1 - u) * RMIN + u * RMAX);
  int g = (int)((1 - u) * GMAX + u * GMIN);
  //int b = (int)((1 - u) * BMIN + u * BMAX);
  
  //out << "u: " << u << ", r: " << r << ", g: " << g /*<< ", b: " << b*/ << "\n";
  
  p->setBrush(QColor(r, g, 0));
  //painter.setBrush(Qt::cyan);
  
  // geen pen voor de rand (zwart als op de driehoek geklikt is)
  if (geklikt)
    p->setPen(Qt::black);
  else
    p->setPen(Qt::NoPen);
  
  // teken de veelhoek
  p->drawPolygon(polygon);
}
