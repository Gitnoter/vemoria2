//----------------------------------------------------------------------
/// \file
/// \brief	Vemoria main function.
/// This is the place where all life starts.
/// \ingroup	g_main
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include <QApplication>
#include "gui/mainwindow.h"
#include "QFile"
#include "QFont"
#include "QDebug"

/// The usual program entry.
/// The main function is as short as possible, as we cannot easily test in in a unit test.
/// Therefore all functionality is held in libraries which are more testable.
int main(int argc, char *argv[])
{
    ///\todo We should parse the command line arguments here.
    QApplication app(argc, argv);

    MainWindow mainwindow;
    mainwindow.showMaximized();


     QFile file(":/fonts/fonts/SourceSansPro-Regular.ttf");

     if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "unable to open font";
     }

     QFont f;
     f.setFamily("Source Sans Pro");
     f.setPointSize(10);
     app.setFont(f);

    return app.exec();
}
