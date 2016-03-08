////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QDir>
#include <QString>
#include <QPointer>
#include "qgit2.h"
class CollectionManager
{
public:
    CollectionManager();
    ~CollectionManager();
    //!
    //!\return Please change the return value if necessary
    //!
    void getCollectionList();
    bool createCollection(QString collectionName);
    void deleteCollection();
private:
    QPointer<LibQGit2::Repository> repo;
};

#endif // COLLECTIONMANAGER_H
