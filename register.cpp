
#include "register.h"

#include "ui_register.h"



register::Register(QWidget *parent()) :
    QWidget(parent),
    ui(new Ui::register)
{
    ui->setupUi(this);
    ui->lineEditPassword->setVisible(false);
    ui->lineEditRegitser->setVisible(false);
    ui->lineEdit_Retypepasswpord->setVisible(false);
}

register::~Register()
{
    delete ui;
}
