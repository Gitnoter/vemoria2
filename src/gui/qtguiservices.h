/// \file
/// \brief	Vemoria QtGuiServices class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#include "gui/mainwindow.h"
#include <QUrl>


#ifndef QTGUISERVICES_H
#define QTGUISERVICES_H
#include "logic/uiservices.h"


class QtGuiServices : public UiServices
{
public:
    QtGuiServices();
    void openURL(MainWindow *window, QUrl path);
};



#endif // QTGUISERVICES_H
