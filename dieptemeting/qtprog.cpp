#include <QtGui>

#include <iostream>

#include "vaart.h"
#include "meting.h"
#include "punt.h"

#define WIDTH 300
#define HEIGHT 500

class MyWidget : public QWidget
{
//Q_OBJECT

public:
  MyWidget(QWidget *parent = 0);
  ~MyWidget();
  void mousePressEvent(QMouseEvent* event);
  vaart *v;

protected:
  virtual void paintEvent(QPaintEvent *event);
};


MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
  setWindowTitle("MyWidget");
  resize(WIDTH, HEIGHT);
    
  v = new vaart();
  v->leesBestand("DATA.dat");
  //v->leesBestand("OELG_B06.dat");
  
  //v->toon(0);
  
  v->maakStroken(WIDTH, HEIGHT);
}

MyWidget::~MyWidget(){
  delete v; //geef vaart v vrij
}

void MyWidget::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  v->teken(&painter);
}

void MyWidget::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    if (event->x() < WIDTH && event->y() < HEIGHT) {
      printf("muis geklikt op %d, %d\n", event->x(), event->y());
      v->bepaalGeklikteDriehoek(event->x(), event->y());
    }
  }
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MyWidget window;
  window.resize(WIDTH, HEIGHT);
  window.setWindowTitle(QApplication::translate("childwidget", "Dieptemeting"));
  window.show();

  return app.exec();
}
