/// \file
/// \brief	Vemoria ItemManager implementation.
/// The ItemManager will instantly apply changes to files in the repository (Items) and provide
/// functionality around files in general.
/// \ingroup	g_logic
///
#include "itemmanager.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QDateTime>


ItemManager::ItemManager(UiServices *newUiservices)
{
    this->uiservices = newUiservices;
}

void ItemManager::getItemDetails(QString const & /*itemname*/) const
{

}

void ItemManager::setItemDetails(QString const & /*itemname*/, QString /*Details*/[] /*, specific Item(Pointer?)*/)
{

}

QString ItemManager::getItemList() const
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

void ItemManager::exportItems(QString /*ItemList*/[])
{

}

void ItemManager::createItem()
{

}

void ItemManager::openItemExternally( Item & /*itemToOpen*/ )
{
    ///
    /// \brief ItemManager::openItemExternally
    /// We kindly ask QDesktopSerivices to open the file.
    ///
    ///
    // QDesktopServices::openUrl(QUrl("file:///"+itemToOpen.getPath(),QUrl::TolerantMode));
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
