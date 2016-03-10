////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#include "collectionmanager.h"
#include "qgit2.h"
#include <QDir>
#include <QTextStream>
#include <QDateTime>


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
    /// \brief new collection with xlm-file in the collection folder
    ///

    QString date = QDateTime::currentDateTime().toString();
    QString vemoriaVersion = "1.0";


        if(!QDir(collectionName).exists())
        {
            QDir directory;
            directory.mkdir(collectionName);
            QFile file;
            file.setFileName(collectionName + "/" + collectionName + ".xml"); // wie wird / gehandelt???
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream stream(&file);
            stream<<"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"<<endl;
            stream<<"<notes>"<<endl;
            stream<<"\t<version>"+vemoriaVersion+"</version>"<<endl;
            stream<<"\t<repName>" + collectionName + "</repName>"<<endl;
            stream<<"\t<createDate>"<< date <<"</createDate>"<<endl;
            stream<<"</notes>"<<endl;
            file.close();

        }
        else return false;

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
