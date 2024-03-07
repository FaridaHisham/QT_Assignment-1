#include "loginwidow.h"
#include "registerwindow.h"
#include "welcomewindow.h"
#include <QApplication>
#include "Users.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginwidow w;
    RegisterWindow r;
    w.show();
    return a.exec();
}
