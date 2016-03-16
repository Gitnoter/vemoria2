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
#include <logic/picture.h>
#include <logic/audio.h>
#include <logic/document.h>
#include <logic/video.h>
#include <QPointer>
#include <QDomElement>




//!
//! \brief The XMLHandler class
//! \param output is the string containing the XML-Elements
//! \param documentName is the Path + document name of an XML-File
//!
class XMLHandler
{
    //!
    //! \brief ListElements-Method for Picture, Audio, Document and Video
    //! \param root
    //! \param picture
    //! \param audio
    //! \param document
    //! \param video
    //! \param tagname
    //!
    static void ListElements_Picture(QDomElement root, QPointer<Picture> picture, QString tagname);
    static void ListElements_Audio(QDomElement root, QPointer<Audio> audio, QString tagname);
    static void ListElements_Document(QDomElement root, QPointer<Document> document, QString tagname);
    static void ListElements_Video(QDomElement root, QPointer<Video> video, QString tagname);
public:
    XMLHandler();
    ~XMLHandler();

    //!
    //! \brief readXMLFile-Method for Picture, Audio, Document and Video
    //! \param documentName (with Path)
    //! \return all Elements of an XML-File
    //!
    static QPointer<Picture> readXMLFile_Picture(QString documentName);
    static QPointer<Audio> readXMLFile_Audio(QString documentName);
    static QPointer<Document> readXMLFile_Document(QString documentName);
    static QPointer<Video> readXMLFile_Video(QString documentName);

    //!
    //! \brief Space for future method to write XML-Files
    //!
//    Picture write_XMLData()
//    {
//    }
};

#endif // XMLHANDLER_H

