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
#include <QVector>
#include <logic/item.h>

/// \class
/// Metadata of video items.
class Video: public Item
{
  public:
    // Default constructors will do.
    virtual ~Video();

    ///@{
    /// Setters and Getters for the attributes.
    /// Nothing special about this.

    QString getDate() const { return date; }
    void setDate(const QString & value) { date=value; }

    QString getTime() const { return time; }
    void setTime(const QString & value) { time=value; }

    QVector<QString> getLocation() const { return location; }
    void setLocation(const QVector<QString> & value) { location=value; }

    QString getGeoposition() const { return geoposition; }
    void setGeoposition(const QString & value) { geoposition=value; }

    QString getCreator() const { return creator; }
    void setCreator(const QString & value) { creator=value; }

    QVector<QString> getPeople() const { return people; }
    void setPeople(const QVector<QString> & value) { people=value; }

    QVector<QString> getEvent() const { return event; }
    void setEvent(const QVector<QString> & value) { event=value; }

    QString getPlaybacktime() const { return playbacktime; }
    void setPlaybacktime(const QString & value) { playbacktime=value; }

    QString getFramerate() const { return framerate; }
    void setFramerate(const QString & value) { framerate=value; }

    QString getDescription() const { return description; }
    void setDescription(const QString & value) { description=value; }

    QString getLicense() const { return license; }
    void setLicense(const QString & value) { license=value; }

    ///
    ///@}

  private:
    QString date;
    QString time;
    QVector<QString> location;
    QString geoposition;
    QString creator;
    QVector<QString> people;
    QVector<QString> event;
    QString playbacktime;
    QString framerate;
    QString description;
    QString license;
};

#endif // VIDEO_H
