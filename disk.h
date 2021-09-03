#include<QWidget>
class space;
class disk: public QWidget
{
private:

    int size;
    space* on;
    int Size(){return size;}
    int pos;

public:
      void setPos(space*down, int p);
      void Lift();
      void paintEvent(QPaintEvent * event);
      disk(int size, space* on,int pos, QWidget*);
      space* On(){return on;}
      friend class space;
};


