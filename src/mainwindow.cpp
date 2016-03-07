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
#include "version.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix13 ("/Users/Dennis/Desktop/pic/pic2.jpg");
    ui->previewPic->setPixmap( pix13.scaled ( 300, 120, Qt::IgnoreAspectRatio, Qt::FastTransformation ));


    ui->userLabel2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


