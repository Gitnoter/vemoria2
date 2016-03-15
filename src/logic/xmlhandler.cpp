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
//! \brief XMLHandler::ListElements
//! \param root
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
//! \brief XMLHandler::readXMLFile
//! \param documentName
//! \return all Elements of an XML-File
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


//void XMLHandler::WriteFile()
//{

//}
