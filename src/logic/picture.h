/// \file
/// \brief	Vemoria picture metadata header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#ifndef PICTURE_H
#define PICTURE_H
#include "logic/item.h"

/// \class
/// Metadata of picture items.
class Picture: public Item
{
  public:
    // Default constructors will do.
    virtual ~Picture();

    ///@{
    /// Setters and Getters for the attributes.
    /// Nothing special about this.

    QString getDate() const { return date; }
    void setDate(const QString & value) { date=value; }

    QString getTime() const { return time; }
    void setTime(const QString & value) { time=value; }

    QString getDescription() const { return description; }
    void setDescription(const QString & value) { description=value; }

    QString getGeoposition() const { return geoposition; }
    void setGeoposition(const QString & value) { geoposition=value; }

    QString getCreator() const { return creator; }
    void setCreator(const QString & value) { creator=value; }

    QString getLicense() const { return license; }
    void setLicense(const QString & value) { license=value; }

    /// \todo add setters and getters for people, event, location
    ///@}

  private:
    QString date;
    QString time;
    QString geoposition;
    QString description;
    QString creator;
    QString license;
    QString people[];		///< \todo use QArray or similar
    QString event[];
    QString location[];
};

#endif // PICTURE_H
