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

class CollectionManager
{
public:
    CollectionManager();
    //!
    //!\return Please change the return value if necessary
    //!
    void getCollectionList();
    bool createCollection(QString collectionName);
    void deleteCollection();
};

#endif // COLLECTIONMANAGER_H
