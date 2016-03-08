////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#include <QApplication>
#include "mainwindow.h"
#include "picture.h"
#include "Repository.h"
#include "xmlhandler.h"
#include <iostream>
#include <QTextStream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString s;

    Picture pic;
    pic.hello();
    XMLHandler handy;
    //Putput in Application Output is chaotic. Two ways to Output the Elements
    QTextStream(stdout) /*<< endl << endl*/ << handy.readXMLFile("C:/beispiel.xml") << endl;

    return a.exec();
}
