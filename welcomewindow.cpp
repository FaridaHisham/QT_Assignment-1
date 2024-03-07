#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwidow.h"
#include "Users.h"

welcomewindow::welcomewindow( QWidget *parent, QString username, QString age)
     :QDialog(parent)
    , ui(new Ui::welcomewindow)
{
    ui->setupUi(this);

    QPixmap pix ("C:\\Users\\mo\\Documents\\Assignment1\\Cinema.jpg.jfif");
    int w = ui ->image2_label->width();
    int h = ui ->image2_label->height();
    ui->image2_label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));


    qDebug() << "Before setText()";

    // Check if ui->Hello_label_2 is not null before accessing it
    if (ui->Hello_label_2) {
        // Set the text of the label
        //QString str = QString ::number(age);
        ui->Hello_label_2->setText("Hello " + username + " " + age);
    }
    else {
        // Print an error message if ui->Hello_label_2 is null
        qDebug() << "Error: Hello_label_2 is not initialized.";
    }

    // After setting the text
    qDebug() << "After setText()";


}

welcomewindow::~welcomewindow()
{
    delete ui;
}



void welcomewindow::on_Logout_pushButton_clicked()
{
    hide();


    loginwidow* loginwindow = new loginwidow(this);
    loginwindow->show();
}

