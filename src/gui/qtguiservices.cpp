#include "qtguiservices.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

QtGuiServices::QtGuiServices()
{

}

void QtGuiServices::openURL(QUrl path)
{
    QDesktopServices::openUrl(QUrl("file:///"+path.toString(),QUrl::TolerantMode));

    path.clear(); //temp

}

void QtGuiServices::deleteURL(QUrl path)
{
    qDebug() << path.toString() << endl;
    QFile::remove(path.toString());
}
