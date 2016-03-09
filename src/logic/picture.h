////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef PICTURE_H
#define PICTURE_H
#include "logic/item.h"



class Picture: public Item
{
    //!
    //! \brief Metadata of Class Picture
    //! \param title
    //! \param date
    //! \param time
    //! \param geoposition
    //! \param description
    //! \param creator
    //! \param license
    //! \param people[]
    //! \param event[]
    //! \param location[]
    //! \param miscellaneous[]
    //!
    QString title;
    QString date;
    QString time;
    QString geoposition;
    QString description;
    QString creator;
    QString license;
    QString people[];
    QString event[];
    QString location[];
    QString miscellaneous[];
public:
    Picture();
};

#endif // PICTURE_H
