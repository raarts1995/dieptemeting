#include "strook.h"

strook::strook() {
  
}

strook::~strook() {
  for (unsigned int i = 0; i < driehoeken.size(); i++)
    delete driehoeken[i];
}

void strook::toon(int d) {
  cout << "stroken\n";
  for (unsigned int i = 0; i < driehoeken.size(); i++)
    driehoeken[i]->toon(d);
}

void strook::voegDriehoekBij(driehoek *d) {
  driehoeken.push_back(d);
}

void strook::setSchaal(schaal *s) {
  for (unsigned int i = 0; i < driehoeken.size(); i++) {
    driehoeken[i]->setSchaal(s);
  }
}

void strook::teken(QPainter *p) {
  for (unsigned int i = 0; i < driehoeken.size(); i++) {
    driehoeken[i]->teken(p);
  }
}

driehoek* strook::getDriehoek(int nr) {
  return driehoeken[nr];
}

int strook::getSize() {
  return driehoeken.size();
}
