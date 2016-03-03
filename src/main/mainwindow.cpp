/*-------------------------------------------------
* This file is a part of the Vemoria project.
*
*
* This project is licensed under the EUPL v.1.1 or a later version.
* -------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
