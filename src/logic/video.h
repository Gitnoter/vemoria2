////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef VIDEO_H
#define VIDEO_H
#include <logic/item.h>
#include <QString>


class Video: Item
{
    //!
    //! \brief Metadata of Class Video
    //! \param title;
    //! \param date;
    //! \param time;
    //! \param location[];
    //! \param geoposition;
    //! \param creator;
    //! \param people[];
    //! \param event[];
    //! \param playbacktime;
    //! \param framerate;
    //! \param description;
    //! \param license;
    //! \param miscellaneous[];
    //!
    QString title;
    QString date;
    QString time;
    QString location[];
    QString geoposition;
    QString creator;
    QString people[];
    QString event[];
    QString playbacktime;
    QString framerate;
    QString description;
    QString license;
    QString miscellaneous[];
public:
    Video();
};

#endif // VIDEO_H
