/// \file
/// \brief	Vemoria collectionmanager cpp file
/// \ingroup	g_repository
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include "collectionmanager.h"
#include "qgit2.h"
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include "vemoria-config.h"

CollectionManager::CollectionManager()
{
    ///
    ///@brief CollectionManager provides an overview of what
    /// Collections are available.
    ///

    repo = new LibQGit2::Repository();
}

CollectionManager::~CollectionManager()
{
    delete repo;
}

void CollectionManager::getCollectionList()
{

}

bool CollectionManager::createCollection(QString collectionName)
{
    ///
    /// \brief new collection with xml-file in the collection folder
    ///
        if(!QDir(collectionName).exists())
        {
            QString date = QDateTime::currentDateTime().toString();
            QString vemoriaVersion = VEMORIA_VERSION;
            QDir directory;
            directory.mkdir(collectionName);
            QFile file;
            file.setFileName(collectionName + "/." + collectionName + ".xml");
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream stream(&file);
            stream<<"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"<<endl;
            stream<<"<notes>"<<endl;
            stream<<"\t<version>"+vemoriaVersion+"</version>"<<endl;
            stream<<"\t<repName>" + collectionName + "</repName>"<<endl;
            stream<<"\t<createDate>"<< date <<"</createDate>"<<endl;
            stream<<"</notes>"<<endl;
            file.close();

#ifdef _WIN32
            QByteArray ba = collectionName.toLatin1();
    system("attrib +h " + ba + "\\." + ba + ".xml");
#endif

        }
        else return false;
    ///
    /// \todo gui has to check if return is false or true to give information to the user
    ///

        try {
            repo->init(collectionName,false);


        }
        catch (const LibQGit2::Exception& ex)
        {

            return false;
        }
        return true;
}


void CollectionManager::deleteCollection()
{

}
