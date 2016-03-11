/// \file
/// \brief	Vemoria XML-Handler base class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <QCoreApplication>
#include <QtCore>
#include <QtXml/QtXml>
#include <QDebug>
#include <picture.h>

//!
//! \brief The XMLHandler class
//! \param output is the string containing the XML-Elements
//! \param documentName is the Path + document name of an XML-File
//!
class XMLHandler
{
    QString documentName;
 //later:
   // Picture pic;
    QString output;

public:
    XMLHandler();

    //!
    //! \brief ListElements
    //! \param root
    //! \param tagname
    //!
    void ListElements(QDomElement root, QString tagname);

    //!
    //! \brief readXMLFile
    //! \param documentName
    //! \return all Elements of an XML-File
    //!
    QString readXMLFile(QString documentName);

    //!
    //! \brief Space for future method to write XML-Files
    //!
   // Picture write_XMLData()
    //{

    //}
};

#endif // XMLHANDLER_H

