#include "space.h"
#include "disk.h"
#include "ui_hanoi.h"
#include <QPainter>

disk::disk(int size, space* on,int pos, QWidget* parent)
{
  this->size = size;
  this->on = on;
  this->pos = pos;
  this->setParent(parent);
  show();
}

void disk::setPos(space* down, int p){

     if(On() != down){
       on = down;
       setParent(down->parentWidget());
       show();
     }
     pos = p;
     repaint();
}

void disk::Lift(){
    pos = 12;
    repaint();
}

void disk::paintEvent(QPaintEvent *event){

    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor edgeDiskColor(0, 0, 0);
    painter.setPen(edgeDiskColor);

    int width = size*5+size*3 + 40;
    QColor colors[] = {QColor(35,110,150), QColor(21,178,211),QColor(255,215,0),  QColor(243,135,47), QColor(255,89,143), QColor(51, 102, 255), QColor(102,0,255), QColor(204,0,255)};
    QColor diskTop = colors[size-1];
    QColor diskShadow = diskTop.darker(140);
    painter.setBrush(diskShadow);
    painter.drawEllipse(QPointF(130,355-23*(pos+1)),width-1,22+size*4);

    painter.setBrush(diskTop);
    painter.drawEllipse(QPointF(130,343-23*(pos+1)),width,24+size*4);

    diskShadow = diskTop.darker(230);
    painter.setBrush(diskShadow);
    painter.drawEllipse(QPointF(130,345-23*(pos+1)),width/4,8);

}

