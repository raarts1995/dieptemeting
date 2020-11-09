#include "meting.h"

using namespace std;

meting::meting() {
  
}

meting::~meting() {
  for (unsigned int i = 0; i < punten.size(); i++) {
    delete punten[i];
  }
}

void meting::toon(int d) {
  insprong::springIn(d);
  cout << "meting\n";
  for (unsigned int i = 0; i < punten.size(); i++)
    punten[i]->toon(d + 1);
}

void meting::voegPuntBij(punt *p) {
  punten.push_back(p);
}

punt* meting::getPunt(int n) {
  if (n >= punten.size())
    return NULL;
  return punten[n];
}

int meting::getSize() {
  return punten.size();
}
