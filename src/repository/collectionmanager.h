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

#include <QString>
#include <QPointer>

namespace LibQGit2 {
  class Repository; // forward declaration
}

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
    void create(QString &collectionName);
    void commit(QString& collectionName, QString& commiter_name, QString& commiter_mail, QString& commitmessage);
private:

};

#endif // COLLECTIONMANAGER_H
