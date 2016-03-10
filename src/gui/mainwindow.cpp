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
#include "repository/collectionmanager.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix13 ("/Users/Dennis/Desktop/pic/pic2.jpg");
    ui->previewPic->setPixmap( pix13.scaled ( 300, 120, Qt::IgnoreAspectRatio, Qt::FastTransformation ));

    ui->userLabel2->show();
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->userLabel2->hide();
    ui->gridDetail->show();
}

void MainWindow::on_actionNew_Collection_triggered()
{
      popupCollection popwindows;
      popwindows.setModal(true);
      popwindows.exec();

}
