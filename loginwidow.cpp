#include "loginwidow.h"
#include "ui_loginwidow.h"
#include "Users.h"
#include"registerwindow.h"
#include"welcomewindow.h"
#include <QMessageBox>

loginwidow::loginwidow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginwidow)

{
    ui->setupUi(this);
    ui->Error_label->setVisible(false);
}

loginwidow::~loginwidow()
{
    ui->Error_label->setVisible(false);
    delete ui;
}


void loginwidow::on_login_pushButton_clicked()

{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_password->text();

    qDebug() << "Username entered:" << username;
    qDebug() << "Password entered:" << password;

    bool correct_user = false;

    for (int i=0; i<sizeof(usernames); ++i)
    {

        if(username==usernames[i] && password==passwords[i] && username!="" && password!="")
        {
            qDebug() << "Login successful for user:" << username;


           // QMessageBox::information (this, "Login", "Username and password is correct);
            hide();


           welcomewindow = new class welcomewindow(this, username, ages[i]);
           welcomewindow->show();

            correct_user = true;

        }


    }
    if (correct_user == false)
    {
        qDebug() << "Login failed for user:" << username;

        QMessageBox::critical (this, "Login", "Username and password is not correct");
        //ui->Error_label->setVisible(true);
    }


}

void loginwidow::on_Register_pushButton_2_clicked()
{
    hide();
    RegisterWindow* registerwindow = new RegisterWindow(this);
    registerwindow->show();
}

