#include "vaart.h"

using namespace std;

vaart::vaart() {
  
}

vaart::~vaart(){
  for (unsigned int i = 0; i < metingen.size(); i++)
    delete metingen[i];
}

void vaart::toon(int d) {
  insprong::springIn(d);
  cout << "vaart\n";
  for (unsigned int i = 0; i < metingen.size(); i++)
    metingen[i]->toon(d + 1);
}

void vaart::voegMetingBij(meting *m) {  
  metingen.push_back(m);
}



//file IO

void vaart::leesBestand(const string &naam) {
  string   lijn;
  ifstream fin;

  fin.open(naam.c_str());
  if(!fin.is_open())
  {
    cout << "Fout bij openen van bestand!\n";
    return;
  }

  for(int i=0;i<8;i++) //lees 8 regels
  {
    getline(fin, lijn);
  }

  getline(fin, lijn); //lees regel 9
  while(!fin.eof())
  {
    //cout << lijn << "\n"; //print regels totat het hele bestand gelezen is
    splitsWoorden(lijn);
    
    //lees volgende lijn
    getline(fin, lijn);
  }
  //cout << "Gelezen!\n";
}

void vaart::splitsWoorden(const string &s) {
  // maak een stream van de string
  // lijn is gedeclareerd als string lijn
  stringstream strstr(s);

  // gebruik stream iterators om de stream als witruimte-gescheiden strings 
  // naar een vector te kopieren
  istream_iterator<string> it(strstr);
  istream_iterator<string> end;
  vector<string> woorden(it, end);
  
  verwerkWoorden(woorden);
  
  // Geef alle woorden weer 
  /*for (unsigned int i=0; i<woorden.size(); i++)
  {
    insprong::springIn(1);
    cout << woorden[i] << "\n";
  }*/
}

void vaart::verwerkWoorden(vector<string> woorden) {
  int aantal = naarInt(woorden[0]);
  //cout << "aantal "<< aantal << "\n";

  double x = naarDouble(woorden[3]);
  //cout << "x "<< x << "\n";

  double y = naarDouble(woorden[4]);
  //cout << "y "<< y << "\n";

  x *= 10000;
  y *= 10000;
  
  meting *m = new meting();
  punt *p;
  
  for (unsigned int pos = 5; pos<woorden.size(); pos++)
  {
    double z = naarDouble(woorden[pos]);
    
    p = new punt(x, y + 0.6 * (pos - 5), z);
    m->voegPuntBij(p);
    
    //cout << "z "<< z << "\n";
  }
  
  voegMetingBij(m);
}

bool vaart::isLeeg(const string &s) {
  return s.empty();
}

int vaart::naarInt(const string &s) {
  int n;

  istringstream(s) >> n;
  return n;
}

double vaart::naarDouble(const string &s) {
  double d;

  istringstream(s) >> d;
  return d;
}

//tekenfuncties

void vaart::maakStroken(int width, int height)
{
  for (unsigned int im = 0; im < metingen.size() - 1; im++) {
    meting *m1 = metingen[im];
    meting *m2 = metingen[im + 1];

    strook  *s = new strook();
    voegStrookBij(s);

    for (int ip = 0; ip < m1->getSize() - 1; ip++) {
      punt *p1 = m1->getPunt(ip);
      punt *p2 = m1->getPunt(ip + 1);
      punt *p3 = m2->getPunt(ip);
      punt *p4 = m2->getPunt(ip + 1);

      driehoek *d1 = new driehoek(p1, p2, p3);
      driehoek *d2 = new driehoek(p2, p3, p4);
      s->voegDriehoekBij(d1);
      s->voegDriehoekBij(d2);
    }
  }
  
  verwerkSchaal(berekenMinMax(), width, height);
  
}

void vaart::voegStrookBij(strook *s) {
  stroken.push_back(s);
}

void vaart::teken(QPainter *p) {
  for (unsigned int i = 0; i < stroken.size(); i++) {
    stroken[i]->teken(p);
  }
}

void vaart::bepaalGeklikteDriehoek(int x, int y) {
  for (int i = 0; i < stroken.size(); i++) {
    for (int j = 0; j < stroken[i]->getSize(); j++)
    {
      if (stroken[i]->getDriehoek(j)->puntBinnenDriehoek(x, y)) {
        stroken[i]->getDriehoek(j)->setGeklikt(true);
	printf("strook %d, driehoek %d\n", i, j);
        //break;
      }
    }
  //break;
  }
}

//minmax functie
minmax* vaart::berekenMinMax() {
  if (metingen.size() == 0)
    return NULL;
  minmax *mm = new minmax();
  mm->minx = mm->maxx = metingen[0]->getPunt(0)->getX();
  mm->miny = mm->maxy = metingen[0]->getPunt(0)->getY();
  mm->minz = mm->maxz = metingen[0]->getPunt(0)->getZ();
  
  for (unsigned int i = 0; i < metingen.size(); i++) {
    for (int j = 0; j < metingen[i]->getSize(); j++) {
      if (metingen[i]->getPunt(j)->getX() < mm->minx)
	mm->minx = metingen[i]->getPunt(j)->getX();
      if (metingen[i]->getPunt(j)->getX() > mm->maxx)
	mm->maxx = metingen[i]->getPunt(j)->getX();
      if (metingen[i]->getPunt(j)->getY() < mm->miny)
	mm->miny = metingen[i]->getPunt(j)->getY();
      if (metingen[i]->getPunt(j)->getY() > mm->maxy)
	mm->maxy = metingen[i]->getPunt(j)->getY();
      if (metingen[i]->getPunt(j)->getZ() < mm->minz)
	mm->minz = metingen[i]->getPunt(j)->getZ();
      if (metingen[i]->getPunt(j)->getZ() > mm->maxz)
	mm->maxz = metingen[i]->getPunt(j)->getZ();
    }
  }
  
  //cout << "minx: " << mm->minx << ",\tmaxx: " << mm->maxx << "\n";
  //cout << "miny: " << mm->miny << ",\tmaxy: " << mm->maxy << "\n";
  //cout << "minz: " << mm->minz << ",\tmaxz: " << mm->maxz << "\n";
  
  return mm;
}

void vaart::verwerkSchaal(minmax *mm, int vensterBreedte, int vensterHoogte) {
  double xoffset = mm->minx;
  double yoffset = mm->miny;
  double xschaal = vensterBreedte / (mm->maxx - mm->minx);
  double yschaal = vensterHoogte / (mm->maxy - mm->miny);
  double zmin = mm->minz;
  double zmax = mm->maxz;
  
  s = new schaal(xoffset, yoffset, xschaal, yschaal, zmin, zmax);
  
  //cout << "xoffset: " << xoffset << ", yoffset: " << ", xschaal; " << xschaal << ", yschaal: " << yschaal << "\n";
  //cout << "zmin: " << zmin << ", zmax" << zmax << "\n";
  
    for (unsigned int i = 0; i < stroken.size(); i++) {
    stroken[i]->setSchaal(s);
  }
}
