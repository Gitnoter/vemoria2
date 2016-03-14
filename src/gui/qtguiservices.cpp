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
void QtGuiServices::openURL()
{

    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C://",
        "All files (*.*);;Text File (*.txt);;Music file(*.mp3)" //*.* bedeutet alle Files,
    );
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));

}
