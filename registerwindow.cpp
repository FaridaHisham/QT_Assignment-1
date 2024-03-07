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

    ui->label_Repassword->setVisible(false);
    ui->label_errorusername->setVisible(false);
    ui->label_register->setVisible(false);
    ui->label_errorage->setVisible(false);

    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString repassword = ui->lineEdit_3->text();
    QString stringyear = ui->Year_lineEdit_5->text();
    int year = stringyear.toInt();


    bool error_found =false;
    for (int i=0; i<sizeof(usernames); ++i)
    {

        if(username==usernames[i])
        {
            ui->label_errorusername->setVisible(true);
            error_found=true;
        }
    }

    if (password != repassword)
    {
        ui->label_Repassword->setVisible(true);
        error_found = true;

    }

    if (2024-year <= 12)
       {

           ui->label_errorage->setVisible(true);
        error_found = true;
    }


    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty() ||
        ui->Year_lineEdit_5->text().isEmpty() ||
        (!ui->Admin_RadioButton->isChecked() && !ui->User_RadioButton->isChecked())  ||
        (!ui->Female_RadioButton->isChecked() && !ui->Male_RadioButton->isChecked()) ||
        (!ui->Action_CheckBox->isChecked() && !ui->Comedy_CheckBox->isChecked() && !ui->Drama_CheckBox->isChecked() && !ui->Horro_CheckBox->isChecked() && !ui->Romance_3->isChecked() && !ui->Other_3->isChecked()))
    {

        ui->label_register->setVisible(true);
        error_found=true;
    }

    if(error_found== false)
    {

        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = 2024-year;
        usersCount = usersCount +1 ;
        hide();

        welcomewindow* WelcomeWindow= new welcomewindow(this,username,2024-year);
        WelcomeWindow->show();


    }





    }

