#include "mainwindow.h"
#include <QApplication>
#include <picture.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Picture *pic;
    pic = new Picture();
    pic->hello();


    delete pic;
    return a.exec();
}
