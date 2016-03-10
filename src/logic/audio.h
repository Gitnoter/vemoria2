/// \file
/// \brief	Vemoria audio metadata header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef AUDIO_H
#define AUDIO_H

#include "logic/item.h"

/// \class
/// Metadata of audio items.
class Audio: public Item
{
  public:
    // Default constructors will do.
    virtual ~Audio();

    /// \todo add setters and getters here

  private:
    QString interpreter[];	///< \todo use QArray or similar
    QString publicationdate;	///< \todo add more documentation
    QString length;
    QString album;
    QString genre[];
    QString titlenumber;
    QString description;
    QString license;
    QString recordlabel;
};

#endif // AUDIO_H
