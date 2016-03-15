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
#include <QStandardItemModel>
#include <logic/picture.h>
#include <logic/audio.h>
#include <logic/document.h>
#include <logic/video.h>
#include <logic/undefined.h>

#include <QtCore>
#include <QtXml/QtXml>
#include <QDebug>
#include <QPointer>

//!
//! \brief The XMLHandler class
//! \param output is the string containing the XML-Elements
//! \param documentName is the Path + document name of an XML-File
//!
class XMLHandler
{
    QString FilePath;

       //!
    //! \brief ListElements
    //! \param root
    //! \param tagname
    //!
    static void ListElements_Picture(QDomElement root, QPointer<Picture> picture, QString tagname);
public:
    XMLHandler();
    ~XMLHandler();

    //!
    //! \brief readXMLFile
    //! \param documentName
    //! \return all Elements of an XML-File
    //!
    static QPointer<Picture> readXMLFile_Picture(QString documentName);

    //!
    //! \brief Space for future method to write XML-Files
    //!
//    Picture write_XMLData()
//    {

//    }
};

#endif // XMLHANDLER_H

