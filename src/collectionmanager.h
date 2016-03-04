#-------------------------------------------------
# Project Vemoria
#
# Vemoria aims to be an environment for archiving multimedia files.
#
#
# This project is licensed under the EUPL v.1.1 or a later version.
#-------------------------------------------------
#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H


class CollectionManager
{
public:
    CollectionManager();
    //!
    //!\return Please change the return value if necessary
    //!
    void getCollectionList();
    void createCollection();
    void deleteCollection();
};

#endif // COLLECTIONMANAGER_H
