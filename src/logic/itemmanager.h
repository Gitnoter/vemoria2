/// \file
/// \brief	Vemoria item manager header file
/// \ingroup	g_logic
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "item.h"
#include <QString>
#include "uiservices.h"

class ItemManager
{
public:
    ItemManager(UiServices *uiservices);
    //!
    //!\return Please change the return value if necessary
    //!\param der Parameter 'Item' bezieht sich auf mögliche Items wie Picture etc, dies muss geändert werden (Als Übergabeparameter, abhängig von dem jeweiligen Itemtyp (Pciture, video,...)
    //!
    void getItemDetails(QString const & itemname) const; //for example grandma.jpg
    void setItemDetails(QString const & itemname, QString Details[]/*, specific Item(Pointer?)*/);//Überladen notwendig für verschiedene Itemtypen?
    QString getItemList() const;
    void saveItem();
    void deleteItem();
    void restoreItem();
    void exportItems(QString ItemList[]);
    void createItem();
    void openItemExternally(Item & itemToOpen);
    void createDir();
    void removeDir();
    void moveItemInDir();
private:
    UiServices *uiservices;
};

#endif // ITEMMANAGER_H
