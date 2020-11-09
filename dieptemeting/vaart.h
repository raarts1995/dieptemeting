#ifndef VAART_H
#define VAART_H
#include "meting.h"
#include "insprong.h"
#include "strook.h"
#include "schaal.h"

#include <iostream>
#include <vector>

#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

class minmax 
{
public:
  double minx;
  double maxx;
  double miny;
  double maxy;
  double minz;
  double maxz;
};

class vaart 
{
private:
   vector<meting *> metingen; //lijst met metingen
   vector<strook *> stroken; //lijst met stroken
   schaal *s;
      
public:
   vaart();  // constructor
   ~vaart(); // destructor
   void toon(int d);
   void voegMetingBij(meting *m);
   
   //file IO
   void leesBestand(const string &naam);
   bool isLeeg(const string &s);
   int naarInt(const string &s);
   double naarDouble(const string &s);
   void splitsWoorden(const string &s);
   void verwerkWoorden(vector<string> woorden);
   
   //teken functies
   void maakStroken(int width, int height);
   void voegStrookBij(strook *s);
   void teken(QPainter *p);
   
   void bepaalGeklikteDriehoek(int x, int y);
   
   //min en max functies
   minmax* berekenMinMax();
   void verwerkSchaal(minmax *mm, int vensterBreedte, int vensterHoogte);
};


#endif
