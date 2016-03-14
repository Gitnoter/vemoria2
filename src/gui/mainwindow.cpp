////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../version.h"
#include <QDebug> //currently here for debugging purposes, obviously
#include "popupcollection.h"
#include "QFontDatabase"
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "qtguiservices.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPixmap pix13 ("/Users/Dennis/Desktop/pic/pic2.jpg");
//    ui->previewPic->setPixmap( pix13.scaled ( 300, 120, Qt::IgnoreAspectRatio, Qt::FastTransformation ));


    ui->gridDetail->hide();

    //RESOURCE SYSTEM TEST

    //    QDir dir(":/");
    //    qDebug() << dir.entryList();
    //    ui->label_12->setText( dir.entryList());
    //    ui->label_12->setPixmap(pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_Font(){

    QFontDatabase database;
    database.addApplicationFont(":/new/fonts/SourceSansPro-Regular.tff");

    QFont f = database.font("myFont", "normal", 12);
    ui->label_9->setFont(f);

}

void MainWindow::on_pushButton_2_clicked()
{
      ui->gridDetail->show();
}

void MainWindow::on_actionNew_Collection_triggered()
{
      popupCollection popwindows;
      popwindows.setModal(true);
      popwindows.exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->gridDetail->close();
}

void MainWindow::on_deleteBtn_clicked()
{

}

void MainWindow::on_saveBtn_clicked()
{

}


void MainWindow::on_pushButton_3_clicked()
{

    QtGuiServices guiServices;
    guiServices.openURL(this, QUrl("",QUrl::TolerantMode));

//    QString filename = QFileDialog::getOpenFileName(
//                this,
//                tr("Open File"), //tr ist der Fenstername
//                   "C://",
//                   "All files (*.*);;Text File (*.txt);;Music file(*.mp3)" //*.* bedeutet alle Files,
//                   );
//    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}

void MainWindow::on_pushButton_4_clicked()
{
        QFile::remove("C:/Users/Sulfi/Desktop/QTremove/bla.txt");
}
