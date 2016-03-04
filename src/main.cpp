////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
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
