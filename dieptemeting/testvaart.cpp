#include <iostream>
#include "punt.h"
#include "meting.h"
#include "vaart.h"

int main()
{
   punt   *p;
   meting *m;   
   vaart  *v;
   
   v = new vaart();
   
   m = new meting();

   p = new punt(1.5, 4.6, 6.7);
   m->voegPuntBij(p);
   
   p = new punt(2.5, 5.6, 7.7);
   m->voegPuntBij(p);

   p = new punt(3.5, 6.6, 8.7);
   m->voegPuntBij(p);
   v->voegMetingBij(m);


   m = new meting();

   p = new punt(10.5, 40.6, 60.7);
   m->voegPuntBij(p);
   
   p = new punt(20.5, 50.6, 70.7);
   m->voegPuntBij(p);

   p = new punt(30.5, 60.6, 80.7);
   m->voegPuntBij(p);
   v->voegMetingBij(m);
   
   
   v->toon(0);
   
   v->maakStroken();
   
   delete v; // geef Vaart vrij
   
   return 0;
}
