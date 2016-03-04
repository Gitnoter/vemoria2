#ifndef COLLECTION_H
#define COLLECTION_H
#include <filter.h>
#include <picture.h>
#include <video.h>
#include <document.h>
#include <audio.h>
#include <undefined.h>
#include <itemmanager.h>
#include <cachemanager.h>


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
