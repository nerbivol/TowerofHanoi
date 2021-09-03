#include <QWidget>
#include <vector>
const int MAX_DISKS = 8;
class disk;
class space : public QWidget
{
private:
    int index;
    int num_disks;
    disk* stack[MAX_DISKS];

public:
    space(int,std::vector<int>,QWidget*);
    space(int,int, QWidget*);
    int getIndex();
    int Num;
    ~space();
    disk* take();
    bool put(disk* newdisk, int v);
    int getNdisks(){return num_disks;};
    void paintEvent(QPaintEvent *event);
};
