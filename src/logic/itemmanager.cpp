/// \file
/// \brief	Vemoria ItemManager implementation.
/// The ItemManager will instantly apply changes to files in the repository (Items) and provide
/// functionality around files in general.
/// \ingroup	g_logic
///
#include "itemmanager.h"

ItemManager::ItemManager()
{

}

void ItemManager::getItemDetails(string /*itemname*/)
{

}

void ItemManager::setItemDetails(string /*itemname*/, string /*Details*/[] /*, specific Item(Pointer?)*/)
{

}

string ItemManager::getItemList()
{
    return "";
}

void ItemManager::saveItem()
{
}

void ItemManager::deleteItem()
{

}

void ItemManager::restoreItem()
{

}

void ItemManager::exportItems(string /*ItemList*/[])
{

}

void ItemManager::createItem()
{

}

void ItemManager::openItemExternally( Item &itemToOpen)
{
    ///
    /// \brief ItemManager::openItemExternally
    /// We kindly ask QDesktopSerivices to open the file.
    ///
    ///
    QDesktopServices::openUrl(QUrl("file:///"+itemToOpen.getPath(),QUrl::TolerantMode));
}

void ItemManager::createDir()
{

}

void ItemManager::removeDir()
{

}

void ItemManager::moveItemInDir()
{

}
