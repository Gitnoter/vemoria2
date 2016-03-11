/// \file
/// \brief	Vemoria mainwindow cpp file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../version.h"
#include "popupcollection.h"
#include "QMessageBox"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridDetail->hide();

    addTags();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//test
void MainWindow::addTags(){

    QLabel *label = new QLabel();
    label->setText("Description");

    QTextEdit *lineedit = new QTextEdit();
    lineedit->setPlaceholderText("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");

    QLabel *label2 = new QLabel();
    label2->setText("Persons");

    QTextEdit *lineedit2 = new QTextEdit();
    lineedit2->setPlaceholderText("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");


    QLabel *label3 = new QLabel();
    label3->setText("Other");

    QTextEdit *lineedit3 = new QTextEdit();
    lineedit3->setPlaceholderText("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");

    ui->formLayout_2->addWidget(label);
    ui->formLayout_2->addWidget(lineedit);
    ui->formLayout_2->addWidget(label2);
    ui->formLayout_2->addWidget(lineedit2);
    ui->formLayout_2->addWidget(label3);
    ui->formLayout_2->addWidget(lineedit3);

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

void MainWindow::on_deleteBtn_clicked()
{

}

void MainWindow::on_saveBtn_clicked()
{

}

void MainWindow::on_actionInfo_triggered()
{
         QMessageBox msgBox;
         QPixmap pix (":/icons/icons/VEM.png");
         msgBox.setWindowIcon(pix);
         msgBox.setTextFormat(Qt::RichText);
         msgBox.setText(
                        "\nThe License of this Sotware is EUPL V. 1.1.<br><br>"
                        "Fonts License: SIL Open Font License, 1.1 &nbsp;<a href='https://www.google.com/fonts#UsePlace:use/Collection:Source+Sans+Pro'>google.com/fonts</a><br><br>"
                        "Icons License: MIT &nbsp;<a href='http://ionicons.com/'>ionicons.com</a><br><br>"
                        "Libqgit2 - C++ Qt License: LGPL &nbsp;<a href='https://projects.kde.org/projects/playground/libs/libqgit2/repository'>projects.kde.org</a><br><br>"
                        "Version Number: " + QString::fromUtf8(VERSION));
         msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->gridDetail->hide();
}
