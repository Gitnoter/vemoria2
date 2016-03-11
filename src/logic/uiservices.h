/// \file
/// \brief	Vemoria UiServices class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef UISERVICES_H
#define UISERVICES_H


class UiServices
{
public:
    UiServices();
    virtual ~UiServices();
    virtual void openURL();
};

#endif // UISERVICES_H
