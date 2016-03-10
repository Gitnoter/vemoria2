
#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QDateTime>
#include "item.h"
using namespace std;


class ItemManager
{
public:
    ItemManager();
    //!
    //!\return Please change the return value if necessary
    //!\param der Parameter 'Item' bezieht sich auf mögliche Items wie Picture etc, dies muss geändert werden (Als Übergabeparameter, abhängig von dem jeweiligen Itemtyp (Pciture, video,...)
    //!
    void getItemDetails(string itemname); //for example grandma.jpg
    void setItemDetails(string itemname, string Details[]/*, specific Item(Pointer?)*/);//Überladen notwendig für verschiedene Itemtypen?
    string getItemList();
    void saveItem();
    void deleteItem();
    void restoreItem();
    void exportItems(string ItemList[]);
    void createItem();
    void openItemExternally(string itemname);
    void createDir();
    void removeDir();
    void moveItemInDir();
};

#endif // ITEMMANAGER_H
