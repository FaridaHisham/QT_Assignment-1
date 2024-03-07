#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include"loginwidow.h"
RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->label_Repassword->setVisible(false);
    ui->label_errorusername->setVisible(false);
    ui->label_register->setVisible(false);
    ui->label_errorage->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString repassword = ui->lineEdit_3->text();
    QString stringyear = ui->Year_lineEdit_5->text();
    int year = stringyear.toInt();

    for (int i=0; i<sizeof(usernames); ++i)
    {

        if(username==usernames[i])
        {
            ui->label_errorusername->setVisible(true);

        }
    }
    if (password != repassword)
    {
        ui->label_Repassword->setVisible(true);

    }
    if (2024-year <= 12)
       {

           ui->label_errorage->setVisible(true);
    }
    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty()|| ui->lineEdit_4->text().isEmpty() ||
        ui->Year_lineEdit_5->text().isEmpty()|| !ui->Gender->isChecked()
        ||!ui->Account_Type_GroupBox->isChecked()
        || !ui->Favourite_Genre_GroupBox->isChecked())
    {

        ui->label_register->setVisible(true);
    }


    }

