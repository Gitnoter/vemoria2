/// \file
/// \brief	Vemoria XML-Handler base class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include "xmlhandler.h"

XMLHandler::XMLHandler()
{

}

//!
//! \brief XMLHandler::ListElements
//! \param root
//! \param tagname
//!
void XMLHandler::ListElements(QDomElement root, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QString ItemInString;
    output ="";

    for(int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement())
        {///


            ItemInString=items.at(i).toElement().text();
         ///
            QDomElement itemele = itemnode.toElement();
            output += ItemInString +"\n";
        }
    }
}

//!
//! \brief XMLHandler::readXMLFile
//! \param documentName
//! \return all Elements of an XML-File
//!
 QString XMLHandler::readXMLFile(QString documentName)
{
   QDomDocument document;

   QFile file(documentName);

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       return "no Content available";
   }
   else
   {
       if(!document.setContent(&file))
       {
           return "no Content available";
       }
       file.close();
   }

   QDomElement root = document.firstChildElement();

   ListElements(root, "Customer");
   //pic.Name = ...
   return output;
}
