#include "space.h"
#include "disk.h"
#include <QWidget>
#include <QPainter>
#include <QMessageBox>


space::space(int index, std::vector<int> value, QWidget* parent)
{
    this->index = index;
    this->num_disks = value.size();
    this->setParent(parent);

    for(int i = 0; i < num_disks; i++){
       disk* newdisk = new disk(value[i],this,i, parent);
       stack[i] = newdisk;
   }
    setEnabled(true);
    show();
    raise();
}

space::space(int index, int value, QWidget * parent)
{
     this->setParent(parent);
     this->index = index;
     this->num_disks = value;

     for(int i=0; i < value; i++){
        disk* newdisk = new disk(value - i,this,i, parent);
        stack[i] = newdisk;
    }
     setEnabled(true);
     show();
     raise();
}


int space::getIndex(){
    return index;
}

void space::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor poleColor(135, 143, 172);
    QColor edgePoleColor(0, 0, 0);
    painter.setPen(edgePoleColor);
    painter.setBrush(poleColor);
    painter.drawRoundedRect(120,90,20,260-(num_disks*23),10,9);
    painter.drawRoundedRect(120,90,20,12,10,8);
    raise();
}


disk* space::take(){
    disk *newdisk = NULL;
    if(num_disks>0){
       newdisk = stack[num_disks -= 1];
       stack[num_disks] = NULL;
       newdisk->Lift();
    }

    return newdisk;
}

bool space::put(disk* newdisk, int v){
    if(num_disks == 0){
        stack[0] = newdisk;
        num_disks++;
        newdisk->setPos(this,0);
        raise();
        return true;
    }else{
        }
        if(stack[num_disks-1]->Size() < newdisk->Size()){
            QMessageBox::warning(this, "Помилка", "Правилами гри заборонено накладати більший диск на менший диск");
            return false;
        }else{
            stack[num_disks] = newdisk;
            num_disks++;
            newdisk->setPos(this,num_disks-1);
            raise();

            if(this->index == 2 and v == num_disks){
                QMessageBox::about(this, "Кінець ігри", "Вітаємо! Ви змогли пройти випробування");
            }
            return true;
        }
}

space::~space(){
    setParent(NULL);
    for (int i = 0; i < num_disks; i++){
        delete stack[i];
    }
}
