#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "hanoi.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MenuWindow *ui;
    Hanoi *hanoi;
};

#endif // MENUWINDOW_H
