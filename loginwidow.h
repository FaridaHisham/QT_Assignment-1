#ifndef LOGINWIDOW_H
#define LOGINWIDOW_H

#include <QDialog>
#include "welcomewindow.h"

namespace Ui {
class loginwidow;
}

class loginwidow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwidow(QWidget *parent = nullptr);
    ~loginwidow();

private slots:
    void on_login_pushButton_clicked();

    void on_Register_pushButton_2_clicked();

private:
    Ui::loginwidow *ui;

    welcomewindow *welcomewindow;
};

#endif // LOGINWIDOW_H
