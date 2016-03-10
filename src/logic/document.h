/// \file
/// \brief	Vemoria audio metadata header file
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
#include "logic/item.h"

/// \class
/// Metadata of document items.
//
class Document: public Item
{
  public:
    // Default constructors will do.
    virtual ~Document();

  private:
    QString subject;
    QString creator;
    QString company;
    QString alterationdate;
    QString numberofpages;
};

#endif // DOCUMENT_H
