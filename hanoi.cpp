#include "hanoi.h"
#include "ui_hanoi.h"
#include <QPainter>
#include <QPixmap>
#include <QInputDialog>
#include <iostream>
#include <QMessageBox>

disk*moving = NULL;

Hanoi::Hanoi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hanoi){
    ui->setupUi(this);

    ui->pushButton_1->setStyleSheet("QPushButton {background: None; border: 0}\
                                     QPushButton:hover {background: None}\
                                     QPushButton:pressed {background: None}");
    ui->pushButton_2->setStyleSheet("QPushButton {background: None; border: 0}\
                                     QPushButton:hover {background: None}\
                                     QPushButton:pressed {background: None}");
    ui->pushButton_3->setStyleSheet("QPushButton {background: None; border: 0}\
                                     QPushButton:hover {background: None}\
                                     QPushButton:pressed {background: None}");

    value = 4;

    spaces[0] = new space(0, value,ui->pushButton_1);
    spaces[1] = new space(1, 0,ui->pushButton_2);
    spaces[2] = new space(2, 0,ui->pushButton_3);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(delayedAction()));
    autoplay= false;
    ui->label_4->setNum(stack.size());
    QMessageBox::information(this, "Старт", "Ваше завдання полягає в тому, щоб перенести диски з першої вежі до третьої. При цьому не можна класти більший диск на менший. Удачі!");

}

void Hanoi::delayedAction(){
    if(autoplay){
        if(!queue.empty()){
            Move autom = queue.dequeue();
            moving = spaces[autom.getFrom()]->take();
            spaces[autom.getTo()]->put(moving, value);
            moving = NULL;
            stack.push(autom);
            ui->label_4->setNum(stack.size());
        }else{
            autoplay = false;
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }

    }else{
        if(stack.empty()){
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }else{
            on_action_Undo_triggered();
        }
    }
}

void Hanoi::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPixmap pix(":/fon/img/PlatformforHunaiTower.tif");
    int w = ui->label_3->width();
    int h = ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w,h+100, Qt::KeepAspectRatio));
    QPixmap pix1(":/fon/img/Fantasy World Wallpapers HD.jpg");
    w = ui->label_5->width();
    h = ui->label_5->height();
    ui->label_5->setPixmap(pix1.scaled(w,h, Qt::KeepAspectRatio));
}

Hanoi::~Hanoi()
{
    delete ui;
    for (int i=0;i<3;i++){
        delete spaces[i];
    }
    moving = NULL;
    stack.clear();
    queue.clear();
}


void Hanoi::on_pushButton_clicked(space* position){
    if(!moving){
        moving = position->take();
    }else{
        int from = moving->On()->getIndex();
        if(position->put(moving, value)){
            Move mov(from,position->getIndex());
            stack.push(mov);
            moving = NULL;
            ui->label_4->setNum(stack.size());
        }else{
            moving->On()->put(moving, value);
            ui->label_4->setNum(stack.size());
            moving = NULL;
        }
    }
}


void Hanoi::CalculateAutoplay(int disks, int from,  int to, int temp){
    if(disks == 0){
        return;
    }else{
        CalculateAutoplay(disks-1,from,temp,to);
        queue.enqueue(Move(from,to));
        CalculateAutoplay(disks-1,temp,to,from);
    }
}

void Hanoi::on_pushButton_1_clicked()
{
    on_pushButton_clicked(spaces[0]);
}

void Hanoi::on_pushButton_2_clicked()
{
   on_pushButton_clicked(spaces[1]);
}

void Hanoi::on_pushButton_3_clicked()
{
     on_pushButton_clicked(spaces[2]);     
}

void Hanoi::on_action_New_triggered()
{

    for (int i = 0;i < 3; i++){
        delete spaces[i];
    }
    if(moving){
        delete moving;
    }
    moving = NULL;
    stack.clear();
    queue.clear();
    ui->label_4->setNum(stack.size());

    spaces[0] = new space(0, value,ui->pushButton_1);
    spaces[1] = new space(1, 0,ui->pushButton_2);
    spaces[2] = new space(2, 0,ui->pushButton_3);
}


void Hanoi::on_action_Undo_triggered()
{
   if(!stack.empty()){
    Move mUndo = stack.pop();
    space* to = NULL;
    space* from = NULL;
    to = spaces[mUndo.getTo()];
    from = spaces[mUndo.getFrom()];
    if(moving){
        moving->On()->put(moving, value);
        moving = NULL;
    }
    moving = to->take();
    from->put(moving, value);
    moving = NULL;
    ui->label_4->setNum(stack.size());
    }
}

void Hanoi::on_action_Undo_All_triggered()
{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    timer->start(100);
}

void Hanoi::on_actionAuto_Play_triggered()

{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    autoplay = true;
    on_action_New_triggered();
    CalculateAutoplay(spaces[0]->getNdisks(), 0,2,1);
    timer->start(100);
}

void Hanoi::on_action_2_triggered()
{
    value = 2;
    ui->action_New->trigger();
}

void Hanoi::on_action_3_triggered()
{
    value = 3;
    ui->action_New->trigger();
}

void Hanoi::on_action_4_triggered()
{
    value = 4;
    ui->action_New->trigger();
}

void Hanoi::on_action_5_triggered()
{
    value = 5;
    ui->action_New->trigger();
}

void Hanoi::on_action_6_triggered()
{
    value = 6;
    ui->action_New->trigger();
}

void Hanoi::on_action_7_triggered()
{
    value = 7;
    ui->action_New->trigger();
}

void Hanoi::on_action_8_triggered()
{
    value = 8;
    ui->action_New->trigger();
}

