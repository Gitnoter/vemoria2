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
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::on_actionInfo_triggered()
{
         QMessageBox msgBox;
         msgBox.setText("\nThe License of this Sotware is EUPL V. 1.1.\n\n"
                        "Fonts License: SIL Open Font License, 1.1\n\n"
                        "Icons License: MIT\n\n"
                        "Libqgit2 - C++ Qt License: LGPL\n\n"
                        "Version Number: " + QString::fromUtf8(VERSION));
         msgBox.exec();
}
