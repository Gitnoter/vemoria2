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

}

void CollectionManager::getCollectionList()
{

}

bool CollectionManager::createCollection(QString collectionName)
{
    QPointer<LibQGit2::Repository> repo;

    const QString repoPath;


        if(!QDir(collectionName).exists())
        {
            QDir directory;
            directory.mkdir(collectionName);
        }
        else return false;

        // Create a new repository object
        repo = new LibQGit2::Repository();
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
