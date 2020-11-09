#include <iostream>
#include "punt.h"
#include "meting.h"

int main()
{
   punt   *p;
   meting *m;   
   
   m = new meting();

   p = new punt(1.5, 4.6, 6.7);
   m->voegPuntBij(p);
   
   p = new punt(2.5, 5.6, 7.7);
   m->voegPuntBij(p);

   p = new punt(3.5, 6.6, 8.7);
   m->voegPuntBij(p);

   m->toon(0);
   
   delete m; // geef Meting vrij
}