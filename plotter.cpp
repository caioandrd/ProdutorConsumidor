#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    for(int i=0; i<30;i++){
        tempo.push_back(i);
        valor.push_back(i);
    }

}

void Plotter::paintEvent(QPaintEvent *p){
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  double x, y, x1, y1;

      brush.setColor(Qt::yellow);
      brush.setStyle(Qt::SolidPattern);

      painter.setBrush(brush);
      pen.setColor(Qt::red);
      pen.setWidth(1);
      painter.setPen(pen);

      painter.drawRect(0,0,width(), height());
      painter.setPen(pen);

      pen.setColor(Qt::blue);
      painter.setPen(pen);

      x = tempo[0]*width();
      y = valor[0]*(height()-valor[0]);

      for(int i=1; i<30; i++){
          x1=tempo[i]*width();
          y1=valor[i]*(height()-valor[i]);
          painter.drawLine(x,y,x1,y1);
          x = x1;
          y = y1;
      }
}
void Plotter::receberdados(vector<double> &t, vector<double> &v){
        tempo= t;
        valor= v;
        repaint();
}

