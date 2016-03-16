/// \file
/// \brief	Vemoria XML-Handler base class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include <QCoreApplication>
#include <QtCore>
#include <QtXml/QtXml>
#include <QDebug>
#include "xmlhandler.h"


XMLHandler::XMLHandler()
{

}

XMLHandler::~XMLHandler()
{

}


//!
//! \brief XMLHandler::ListElements_Picture
//! \param root
//! \param picture
//! \param tagname
//!
void XMLHandler::ListElements_Picture(QDomElement root, QPointer<Picture> picture, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString xmlelement;
    QVector<QString> xmlelementlist;

    for(int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement())
        {
            xmlelement=items.at(i).toElement().text();

            if(itemnode.nodeName() == tagname)
            {
                if (tagname =="title")
                {
                    picture->setTitle(xmlelement);
                    qDebug() << tagname + "(): " + picture->getTitle() << endl;
                }
                else if (tagname =="date")
                {
                    picture->setDate(xmlelement);
                    qDebug() << tagname + "(): " + picture->getDate() << endl;
                }
                else if (tagname =="time")
                {
                    picture->setTime(xmlelement);
                    qDebug() << tagname + "(): " + picture->getTime() << endl;
                }
                else if (tagname =="geoposition")
                {
                    picture->setGeoposition(xmlelement);
                    qDebug() << tagname + "(): " + picture->getGeoposition() << endl;
                }
                else if (tagname =="description")
                {
                    picture->setDescription(xmlelement);
                    qDebug() << tagname + "(): " + picture->getDescription() << endl;
                }
                else if (tagname =="creator")
                {
                    picture->setCreator(xmlelement);
                    qDebug() << tagname + "(): " + picture->getCreator() << endl;
                }
                else if (tagname =="license")
                {
                    picture->setLicense(xmlelement);
                    qDebug() << tagname + "(): " + picture->getLicense() << endl;
                }
                else if (tagname =="people")
                {
                    xmlelementlist.append(xmlelement);
                }
                else if (tagname =="event")
                {
                    xmlelementlist.append(xmlelement);
                }
                else if (tagname =="location")
                {
                    xmlelementlist.append(xmlelement);
                }
            }
            else
            {
                qDebug() << "the tagname is invalid " << itemnode.nodeName() << endl;
            }

            if (tagname == "people")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Person" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                picture->setPeople(xmlelementlist);
            }
            else if (tagname == "event")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Event" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                picture->setEvent(xmlelementlist);
            }
            else if (tagname == "location")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Location" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                picture->setLocation(xmlelementlist);
            }
        }
    }
}

//!
//! \brief XMLHandler::readXMLFile_Picture
//! \param documentName
//! \return Picture-Objekt
//!
QPointer<Picture> XMLHandler::readXMLFile_Picture(QString documentName)
{
    QPointer<Picture> picture = new Picture();
   QDomDocument document;

   QFile file(documentName);

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Failed to open file";
   }
   else
   {
       if(!document.setContent(&file))
       {
           qDebug() << "Failed to open file";
       }
       file.close();
   }

   QDomElement root = document.firstChildElement();

   //List all Elements of the Datatype here
   ListElements_Picture(root, picture, "title");
   ListElements_Picture(root, picture, "date");
   ListElements_Picture(root, picture, "time");
   ListElements_Picture(root, picture, "geoposition");
   ListElements_Picture(root, picture, "description");
   ListElements_Picture(root, picture, "creator");
   ListElements_Picture(root, picture, "license");
   ListElements_Picture(root, picture, "people");
   ListElements_Picture(root, picture, "event");
   ListElements_Picture(root, picture, "location");

   return picture;
}


//!
//! \brief XMLHandler::ListElements_Audio
//! \param root
//! \param audio
//! \param tagname
//!
void XMLHandler::ListElements_Audio(QDomElement root, QPointer<Audio> audio, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString xmlelement;
    QVector<QString> xmlelementlist;

    for(int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement())
        {
            xmlelement=items.at(i).toElement().text();

            if(itemnode.nodeName() == tagname)
            {
                if (tagname =="title")
                {
                    audio->setTitle(xmlelement);
                    qDebug() << tagname + "(): " + audio->getTitle() << endl;
                }
                else if (tagname =="publicationdate")
                {
                    audio->setPublicationdate(xmlelement);
                    qDebug() << tagname + "(): " + audio->getPublicationdate() << endl;
                }
                else if (tagname =="length")
                {
                    audio->setLength(xmlelement);
                    qDebug() << tagname + "(): " + audio->getLength() << endl;
                }
                else if (tagname =="album")
                {
                    audio->setAlbum(xmlelement);
                    qDebug() << tagname + "(): " + audio->getAlbum() << endl;
                }
                else if (tagname =="description")
                {
                    audio->setDescription(xmlelement);
                    qDebug() << tagname + "(): " + audio->getDescription() << endl;
                }
                else if (tagname =="titlenumber")
                {
                    int titlenumber = xmlelement.toInt();
                    audio->setTitlenumber(titlenumber);
                    qDebug() << tagname + "(): " + audio->getTitlenumber() << endl;
                }
                else if (tagname =="license")
                {
                    audio->setLicense(xmlelement);
                    qDebug() << tagname + "(): " + audio->getLicense() << endl;
                }
                else if (tagname =="recordlabel")
                {
                    audio->setRecordlabel(xmlelement);
                    qDebug() << tagname + "(): " + audio->getRecordlabel() << endl;
                }
                else if (tagname =="interpreter")
                {
                    xmlelementlist.append(xmlelement);
                }
                else if (tagname =="genre")
                {
                    xmlelementlist.append(xmlelement);
                }
            }
            else
            {
                qDebug() << "the tagname is invalid " << itemnode.nodeName() << endl;
            }

            if (tagname == "interpreter")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Interpreter" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                audio->setInterpreter(xmlelementlist);
            }
            else if (tagname == "genre")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Genre" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                audio->setGenre(xmlelementlist);
            }
        }
    }
}

//!
//! \brief XMLHandler::readXMLFile_Audio
//! \param documentName
//! \return Audio-Object
//!
QPointer<Audio> XMLHandler::readXMLFile_Audio(QString documentName)
{
    QPointer<Audio> audio = new Audio();
   QDomDocument document;

   QFile file(documentName);

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Failed to open file";
   }
   else
   {
       if(!document.setContent(&file))
       {
           qDebug() << "Failed to open file";
       }
       file.close();
   }

   QDomElement root = document.firstChildElement();

   //List all Elements of the Datatype here
   ListElements_Audio(root, audio, "title");
   ListElements_Audio(root, audio, "publicationdate");
   ListElements_Audio(root, audio, "length");
   ListElements_Audio(root, audio, "album");
   ListElements_Audio(root, audio, "description");
   ListElements_Audio(root, audio, "titlenumber");
   ListElements_Audio(root, audio, "license");
   ListElements_Audio(root, audio, "recordlabel");
   ListElements_Audio(root, audio, "interpreter");
   ListElements_Audio(root, audio, "genre");

   return audio;
}



//!
//! \brief XMLHandler::ListElements_Document
//! \param root
//! \param document
//! \param tagname
//!
void XMLHandler::ListElements_Document(QDomElement root, QPointer<Document> document, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString xmlelement;
    QVector<QString> xmlelementlist;

    for(int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement())
        {
            xmlelement=items.at(i).toElement().text();

            if(itemnode.nodeName() == tagname)
            {
                if (tagname =="title")
                {
                    document->setTitle(xmlelement);
                    qDebug() << tagname + "(): " + document->getTitle() << endl;
                }
                else if (tagname =="creator")
                {
                    document->setCreator(xmlelement);
                    qDebug() << tagname + "(): " + document->getCreator() << endl;
                }
                else if (tagname =="company")
                {
                    document->setCompany(xmlelement);
                    qDebug() << tagname + "(): " + document->getCompany() << endl;
                }
                else if (tagname =="alterationdate")
                {
                    document->setAlterationdate(xmlelement);
                    qDebug() << tagname + "(): " + document->getAlterationdate() << endl;
                }
                else if (tagname =="numberofpages")
                {
                    document->setNumberofpages(xmlelement);
                    qDebug() << tagname + "(): " + document->getNumberofpages() << endl;
                }
                else if (tagname =="subject")
                {
                    xmlelementlist.append(xmlelement);
                }
            }
            else
            {
                qDebug() << "the tagname is invalid " << itemnode.nodeName() << endl;
            }

            if (tagname == "subject")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Subject" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                document->setSubject(xmlelementlist);
            }
        }
    }
}

//!
//! \brief XMLHandler::readXMLFile_Document
//! \param documentName
//! \return Document-Object
//!
QPointer<Document> XMLHandler::readXMLFile_Document(QString documentName)
{
    QPointer<Document> document = new Document();
   QDomDocument documents;

   QFile file(documentName);

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Failed to open file";
   }
   else
   {
       if(!documents.setContent(&file))
       {
           qDebug() << "Failed to open file";
       }
       file.close();
   }

   QDomElement root = documents.firstChildElement();

   //List all Elements of the Datatype here
   ListElements_Document(root, document, "title");
   ListElements_Document(root, document, "creator");
   ListElements_Document(root, document, "company");
   ListElements_Document(root, document, "alterationdate");
   ListElements_Document(root, document, "numberofpages");
   ListElements_Document(root, document, "subject");

   return document;
}

//!
//! \brief XMLHandler::ListElements_Video
//! \param root
//! \param video
//! \param tagname
//!
void XMLHandler::ListElements_Video(QDomElement root, QPointer<Video> video, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString xmlelement;
    QVector<QString> xmlelementlist;

    for(int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement())
        {
            xmlelement=items.at(i).toElement().text();

            if(itemnode.nodeName() == tagname)
            {
                if (tagname =="title")
                {
                    video->setTitle(xmlelement);
                    qDebug() << tagname + "(): " + video->getTitle() << endl;
                }
                else if (tagname =="date")
                {
                    video->setDate(xmlelement);
                    qDebug() << tagname + "(): " + video->getDate() << endl;
                }
                else if (tagname =="time")
                {
                    video->setTime(xmlelement);
                    qDebug() << tagname + "(): " + video->getTime() << endl;
                }
                else if (tagname =="geoposition")
                {
                    video->setGeoposition(xmlelement);
                    qDebug() << tagname + "(): " + video->getGeoposition() << endl;
                }
                else if (tagname =="creator")
                {
                    video->setCreator(xmlelement);
                    qDebug() << tagname + "(): " + video->getCreator() << endl;
                }
                else if (tagname =="playbacktime")
                {
                    video->setPlaybacktime(xmlelement);
                    qDebug() << tagname + "(): " + video->getPlaybacktime() << endl;
                }
                else if (tagname =="framerate")
                {
                    video->setFramerate(xmlelement);
                    qDebug() << tagname + "(): " + video->getFramerate() << endl;
                }
                else if (tagname =="description")
                {
                    video->setDescription(xmlelement);
                    qDebug() << tagname + "(): " + video->getDescription() << endl;
                }
                else if (tagname =="license")
                {
                    video->setLicense(xmlelement);
                    qDebug() << tagname + "(): " + video->getLicense() << endl;
                }
                else if (tagname =="location")
                {
                    xmlelementlist.append(xmlelement);
                }
                else if (tagname =="people")
                {
                    xmlelementlist.append(xmlelement);
                }
                else if (tagname =="event")
                {
                    xmlelementlist.append(xmlelement);
                }
            }
            else
            {
                qDebug() << "the tagname is invalid " << itemnode.nodeName() << endl;
            }

            if (tagname == "location")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Location" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                video->setLocation(xmlelementlist);
            }
            else if (tagname == "people")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Person" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                video->setPeople(xmlelementlist);
            }
            else if (tagname == "Event")
            {
                for(int j=i; j < xmlelementlist.count(); ++j)
                {
                    qDebug() << "Event" << j << ": " <<xmlelementlist.at(j) << endl;
                }

                video->setEvent(xmlelementlist);
            }
        }
    }
}

//!
//! \brief XMLHandler::readXMLFile_Video
//! \param documentName
//! \return Video-Object
//!
QPointer<Video> XMLHandler::readXMLFile_Video(QString documentName)
{
    QPointer<Video> video = new Video();
   QDomDocument document;

   QFile file(documentName);

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Failed to open file";
   }
   else
   {
       if(!document.setContent(&file))
       {
           qDebug() << "Failed to open file";
       }
       file.close();
   }

   QDomElement root = document.firstChildElement();

   //List all Elements of the Datatype here
   ListElements_Video(root, video, "title");
   ListElements_Video(root, video, "Date");
   ListElements_Video(root, video, "time");
   ListElements_Video(root, video, "geoposition");
   ListElements_Video(root, video, "creator");
   ListElements_Video(root, video, "playbacktime");
   ListElements_Video(root, video, "framerate");
   ListElements_Video(root, video, "description");
   ListElements_Video(root, video, "license");
   ListElements_Video(root, video, "recordlabel");
   ListElements_Video(root, video, "interpreter");
   ListElements_Video(root, video, "genre");

   return video;
}


//void XMLHandler::WriteFile()
//{

//}
