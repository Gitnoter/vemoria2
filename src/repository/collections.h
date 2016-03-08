////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#include "repository/collection.h"
#include "repository/collectionmanager.h"


class Collections
{
public:
    Collections();
    //!
    //!\return Please change the return value if necessary
    //!
    void Init();
    void Load();
};

#endif // COLLECTIONS_H
