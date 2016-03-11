/// \file
/// \brief	Vemoria item base class header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <QString>

/// \class
/// The base class of all items.
///
/// We use QString for easy interaction with Qt libs. std::string is not
/// suitable, as it doesn't hold UTF-8, and std::wstring conversion to
/// QString for GUI etc. is effort we can avoid by using QString as general
/// string class.

/*! \brief Item Base Class.
 *         .
 *
 *  Containing the Metadata and Tags generic for any item.
 */
 
class Item
{
  public:
    // Default constructors will do.
    virtual ~Item();	///< As Item is a base class, the destructor must be virtual.


    QString getTitle() const { return title; }
    void setTitle(QString & newTitle) { title=newTitle; }

    QString getNotes() const { return notes; }
    void setNotes(QString & newNotes) { notes=newNotes; }


  private:
    QString title;		///< The Item's title.
    QString notes;		///< Miscellaneous notes to add.
};

#endif // ITEM_H
