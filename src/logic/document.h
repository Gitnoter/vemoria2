/// \file
/// \brief	Vemoria document metadata header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
//
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QVector>
#include "logic/item.h"

/*! \brief Document Class.
 *         .
 *
 *  Containing the Metadata and Tags for a specific document item.
 */
 
class Document: public Item
{
  public:
    // Default constructors will do.
    virtual ~Document();


    QVector<QString> getSubject() const { return subject; }
    void setSubject(const QVector<QString> & value) { subject=value; }

    QString getCreator() const { return creator; }
    void setCreator(const QString & value) { creator=value; }

    QString getCompany() const { return company; }
    void setCompany(const QString & value) { company=value; }

    QString getAlterationdate() const { return alterationdate; }
    void setAlterationdate(const QString & value) { alterationdate=value; }

    QString getNumberofpages() const { return numberofpages; }
    void setNumberofpages(const QString & value) { numberofpages=value; }


  private:

    QVector<QString> subject;
    QString creator;
    QString company;
    QString alterationdate;
    QString numberofpages;
};

#endif // DOCUMENT_H
