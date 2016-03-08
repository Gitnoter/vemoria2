////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H
#include <logic/cache.h>


class CacheManager
{
public:
    CacheManager();
    //!
    //!\return Please change the return value if necessary
    //!
    void checkCache();
};

#endif // CACHEMANAGER_H
