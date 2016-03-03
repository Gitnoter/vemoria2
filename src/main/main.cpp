/*-------------------------------------------------
* This file is a part of the Vemoria project.
*
*
* This project is licensed under the EUPL v.1.1 or a later version.
* -------------------------------------------------*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
