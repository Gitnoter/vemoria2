////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef COLLECTION_H
#define COLLECTION_H
#include "logic/filter.h"
#include "logic/picture.h"
#include "logic/video.h"
#include "logic/document.h"
#include "logic/audio.h"
#include "logic/undefined.h"
#include "logic/itemmanager.h"
#include "logic/cachemanager.h"


class Collection
{
    bool shared;
public:
    Collection();
    //!
    //!\return Please change the return value if necessary
    //!
    void fillCollection();
    void updateItem();


};

#endif // COLLECTION_H
