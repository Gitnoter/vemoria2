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

/// The usual program entry.
/// The main function is as short as possible, as we cannot easily test in in a unit test.
/// Therefore all functionality is held in libraries which are more testable.
int main(int argc, char *argv[])
{
    ///\todo We should parse the command line arguments here.
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.showMaximized();

    return app.exec();
}
