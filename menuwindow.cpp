#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/fon/img/gradient.jpg");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->pushButton->setStyleSheet("QPushButton {background-image: url(:/fon/img/btn_newgame.png);\
                                                background-position: top;\
                                                border: 0;\
                                                border-radius: 15px;}\
                                   QPushButton:hover {background-image:url(:/fon/img/btn_newgame_hover.png);\
                                                      background-position: top;}");


    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20);
    effect->setOffset(9,9);
    ui->pushButton->setGraphicsEffect(effect);
    show();

    ui->pushButton_2->setStyleSheet("QPushButton {background-image: url(:/fon/img/btn_about.png);\
                                                  background-position: top;\
                                                  border: 0;\
                                                  border-radius: 15px;}\
                                     QPushButton:hover {background-image:url(:/fon/img/btn_about_hover.png);\
                                                        background-position: top;}");

    QGraphicsDropShadowEffect* effect1 = new QGraphicsDropShadowEffect();
    effect1->setBlurRadius(20);
    effect1->setOffset(9,9);
    ui->pushButton_2->setGraphicsEffect(effect1);
    show();

    ui->pushButton_3->setStyleSheet("QPushButton {background-image: url(:/fon/img/btn_exit.png);\
                                                  background-position: top;\
                                                  border: 0;\
                                                  border-radius: 15px;}\
                                     QPushButton:hover {background-image:url(:/fon/img/btn_exit_hover.png);\
                                                        background-position: top;}");

    QGraphicsDropShadowEffect* effect2 = new QGraphicsDropShadowEffect();
    effect2->setBlurRadius(20);
    effect2->setOffset(9,9);
    ui->pushButton_3->setGraphicsEffect(effect2);
    show();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_pushButton_clicked()
{
    hide();
    hanoi = new Hanoi(this);
    hanoi->show();
}


void MenuWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "About", "Ігра під назвою \"Ханойскі вежі\" \n"
                                      "Автор: Бірук Сергій Володимирович\n"
                                      "Розробленна спеціально для курсової роботи.\n"
                                      "\"НТУУ КПІ\" ІПСА\n"
                                      "2020");

}
