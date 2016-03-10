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
#include <QVector>
#include "logic/item.h"

/// \class
/// Metadata of audio items.

/*! \brief Audio Class.
 *         .
 *
 *  Containing the Metadata and Tags for a specific audio item.
 */
 class Audio: public Item
{
  public:
    // Default constructors will do.
    virtual ~Audio();


    QVector<QString> getInterpreter() const { return interpreter; }
    void setInterpreter(const QVector<QString> & value) { interpreter=value; }

    QString getPublicationdate() const { return publicationdate; }
    void setPublicationdate(const QString & value) { publicationdate=value; }

    QString getLength() const { return length; }
    void setLength(const QString & value) { length=value; }

    QString getAlbum() const { return album; }
    void setAlbum(const QString & value) { album=value; }

    QVector<QString> getGenre() const { return genre; }
    void setGenre(const QVector<QString> & value) { genre=value; }

    int getTitlenumber() const { return titlenumber; }
    void setTitlenumber(const int & value) { titlenumber=value; }

    QString getDescription() const { return description; }
    void setDescription(const QString & value) { description=value; }

    QString getLicense() const { return license; }
    void setLicense(const QString & value) { license=value; }

    QString getRecordlabel() const { return recordlabel; }
    void setRecordlabel(const QString & value) { recordlabel=value; }

  private:
    QVector<QString> interpreter;
    QString publicationdate;	
    QString length;
    QString album;
    QVector<QString> genre;
    int titlenumber;
    QString description;
    QString license;
    QString recordlabel;
};

#endif // AUDIO_H
