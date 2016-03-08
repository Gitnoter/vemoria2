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

        if(!QDir(collectionName).exists())
        {
            QDir directory;
            directory.mkdir(collectionName);
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

bool CollectionManager::addFile(QFile file)
{
//        try {
//            repo->
//        }
}

void CollectionManager::deleteCollection()
{

}
