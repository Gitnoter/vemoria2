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

void QtGuiServices::openURL(MainWindow *window, QUrl path)
{

    QString filename = QFileDialog::getOpenFileName(
        window,
        "Open File",
        "C://",
        "All files (*.*);;Text File (*.txt);;Music file(*.mp3)" //*.* bedeutet alle Files,
    );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));

    path.clear(); //temp

}

void QtGuiServices::deleteURL(QUrl path)
{
    path.clear();
}
