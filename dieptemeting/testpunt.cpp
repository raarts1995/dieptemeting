#include <iostream>
#include "punt.h"

using namespace std;

int main() {
  punt *p;
  
  cout << "start\n";
  
  // maak dynamisch een nieuw object
  p = new punt(1.5, 4.6, 6.7);
  p->toon(0);
  delete p;
  
  cout << "stop\n";
}