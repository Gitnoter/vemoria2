////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef AUDIO_H
#define AUDIO_H
#include "logic/item.h"
#include <QString>


class Audio: Item
{
    //!
    //! \brief Metadata of Class Audio
    //! \param title
    //! \param interpreter[]
    //! \param publicationdate
    //! \param length
    //! \param album
    //! \param genre[]
    //! \param titlenumber
    //! \param description
    //! \param license
    //! \param recordlabel
    //! \param miscellaneous[]
    //!
    QString title;
    QString interpreter[];
    QString publicationdate;
    QString length;
    QString album;
    QString genre[];
    QString titlenumber;
    QString description;
    QString license;
    QString recordlabel;
    QString miscellaneous[];
public:
    Audio();
};

#endif // AUDIO_H
