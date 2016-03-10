/// \file
/// \brief	Vemoria video metadata header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#ifndef VIDEO_H
#define VIDEO_H
#include <logic/item.h>

/// \class
/// Metadata of video items.
class Video: public Item
{
  public:
    // Default constructors will do.
    virtual ~Video();

    /// \todo add setters and getters here

  private:
    QString date;
    QString time;
    QString location[];		///< \todo use QArray or similar
    QString geoposition;
    QString creator;
    QString people[];
    QString event[];
    QString playbacktime;
    QString framerate;
    QString description;
    QString license;
};

#endif // VIDEO_H
