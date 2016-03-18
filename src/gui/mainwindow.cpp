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
#include "logic/picture.h"
#include "logic/xmlhandler.h"

#include <QDebug> //currently here for debugging purposes, obviously
#include "popupcollection.h"
#include "QMessageBox"
#include <QTextEdit>
#include <QApplication>
#include <QDesktopWidget>
#include <copydialog.h>
#include <selectcollection.h>
#include <QDir>
#include <QLayout>
#include <QListWidgetItem>
#include <QSize>
#include <QFileDialog>
#include <QDebug>
#include "QFontDatabase"
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "qtguiservices.h"
#include <repository/collectionmanager.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridDetail->hide();

    trigger = false;
    addTags();


    dirModel = new QFileSystemModel(this);

    fileModel = new QFileSystemModel(this);

    ui->listView->setModel(fileModel);

    QDir directory = QDir::home();
    QString path = directory.path() + "/.vemoria";
    ui->listView->setRootIndex(fileModel->setRootPath(path));

    countRepoItems();

}

void MainWindow::resizeEvent(QResizeEvent*)
{
    QSize windowSize;
    windowSize = size();

    int y  = 0;
    y = windowSize.height();
    int size = y - 150;

    ui->scrollArea->resize(298, size);

    qApp->processEvents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//test metedata
void MainWindow::addTags(){

    QLabel *label = new QLabel();
    label->setText("Description");

    lineedit = new QTextEdit();
    lineedit->setPlaceholderText(description);

    QLabel *label2 = new QLabel();
    label2->setText("Persons");

    QTextEdit *lineedit2 = new QTextEdit();
    lineedit2->setPlaceholderText(description);

    QLabel *label3 = new QLabel();
    label3->setText("Other");

    QTextEdit *lineedit3 = new QTextEdit();
    lineedit3->setPlaceholderText("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");

    QTextEdit *lineedit4 = new QTextEdit();
    lineedit4->setPlaceholderText("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");

    QTextEdit *lineedit5 = new QTextEdit();
    lineedit5->setPlaceholderText("lassst ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut ");

    ui->formLayout_2->addWidget(label);
    ui->formLayout_2->addWidget(lineedit);
    ui->formLayout_2->addWidget(label2);
    ui->formLayout_2->addWidget(lineedit2);
    ui->formLayout_2->addWidget(label3);
    ui->formLayout_2->addWidget(lineedit3);
    ui->formLayout_2->addWidget(lineedit4);
    ui->formLayout_2->addWidget(lineedit5);
}

//show popupCollection
void MainWindow::on_actionNew_Collection_triggered()
{
    popupCollection popwindows;
    popwindows.setModal(true);
    popwindows.exec();
}

//about message box
void MainWindow::on_actionInfo_triggered()
{
    QMessageBox msgBox;
    QPixmap pix (":/icons/icons/VEM.png");
    msgBox.setWindowIcon(pix);
    msgBox.setWindowTitle("Vemoria");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(
                "\nThe License of this Sotware is EUPL V. 1.1.<br><br>"
                "Fonts License: SIL Open Font License, 1.1 &nbsp;<a href='https://www.google.com/fonts#UsePlace:use/Collection:Source+Sans+Pro'>google.com/fonts</a><br><br>"
                "Icons License: MIT &nbsp;<a href='http://ionicons.com/'>ionicons.com</a><br><br>"
                "Icons Files License: Freebie License &nbsp;<a href='http://www.dreamstale.com/free-download-50-file-type-vector-icons/'>dreamstale.com</a><br><br>"
                "Libqgit2 - C++ Qt License: LGPL &nbsp;<a href='https://projects.kde.org/projects/playground/libs/libqgit2/repository'>projects.kde.org</a><br><br>"
                "Version Number: " + QString::fromUtf8(VERSION));
    msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->gridDetail->hide();
}


void MainWindow::on_addButton_clicked()
{
    selectCollection selectColl;
    selectColl.setModal(true);
    selectColl.exec();
}

//count items in the contentWindow & show path
void MainWindow::countItems(QString path){

    int counter = 0;

    //extend filter
    QDirIterator it(path, QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        counter++;
    }

    QString itemsCounterString = QString::number(counter);

    ui->countItemsLabel->setText(itemsCounterString);
    ui->pathLabel->setText(path + "/");
}

//show files in contentWindow
void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    //fileModel = new QFileSystemModel(this);

    ui->imageList->setModel(fileModel);

    QString mPath = fileModel->fileInfo(index).absoluteFilePath();


    QDir dirName = mPath;
    QString dirNameString = dirName.dirName();

    collectionName = dirNameString;

    //warning no subdirs
    QString newPath = mPath + "/files";
    countItems(newPath);

    ui->imageList->setRootIndex(fileModel->setRootPath(newPath));
}


//show file in detail bar
void MainWindow::on_imageList_clicked(const QModelIndex &index)
{
    QString mPath = fileModel->fileInfo(index).absoluteFilePath();

    QFileInfo filetester (mPath);

    bool  trueDir =   filetester.isDir();

    if(trueDir == false){
        QFileInfo file(mPath);

        QString suffix  =  file.suffix();

        if(suffix == "png" || suffix == "jpg" || suffix == "jpeg" || suffix == "bmp" || suffix == "jng" || suffix == "jp2" || suffix  == "img"){

            Picture * picture = new Picture();
            XMLHandler xmlhandler;
            picture = xmlhandler.readXMLFile_Picture(mPath+".xml");
            description = picture->getDescription();
            QTextEdit *lineediti = new QTextEdit();
            lineediti->setText(/*description*/"hallo");
            ui->formLayout_2->addWidget(lineediti);
//            lineedit=new QTextEdit();
//            lineedit->setText(description);


            QPixmap pix(mPath);
            QSize picSize =  pix.size();
            int height = picSize.height();
            int width  = picSize.width();

            //resize Image to widget size
            if(height > 265){
                ui->imagePreview->setPixmap(pix.scaled (265, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation ));
            }
            else{
                ui->imagePreview->setPixmap(pix.scaled (width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation ));
            }
        }
        else{
            QPixmap pix(":/fileIcons/fileIcons/"+ suffix +".png");
            ui->imagePreview->setPixmap(pix.scaled (100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation ));
        }

        ui->editFiles->setText(file.fileName());

        nameFile = file.fileName();

        pathFile = mPath;

        ui->gridDetail->show();

        //not the best solution....
        if(trigger == false){

            const int width = QApplication::desktop()->width();

            QSize windowSize;
            windowSize = size();

            int y  = 0;
            y = windowSize.height();

            //trigger the resize event to expand the scrollarea
            resize(width,  y - 1);
            resize(width,  y + 1);

            trigger = true;
        }
    }
    else{
        ui->imageList->setModel(fileModel);

        QString mPath = fileModel->fileInfo(index).absoluteFilePath();

        //warning no subdirs
        QString newPath = mPath + "/files";
        countItems(newPath);

        ui->imageList->setRootIndex(fileModel->setRootPath(newPath));
    }
}

//save file changes
void MainWindow::on_saveBtn_clicked()
{
    //check if for illegal expression
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    QString getFileName = ui->editFiles->text();
    QDir renameFile = (absolut);

    if(nameFile != getFileName){
        renameFile.rename(nameFile, getFileName);
        ui->imageList->setRootIndex(fileModel->setRootPath(absolut));
    }
}

void MainWindow::countRepoItems(){

    int counter = 0;

    //extend filter
    QDirIterator it("C:/Users/Dennis/.Vemoria", QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        counter++;
    }

    QString itemsCounterString = QString::number(counter);
    ui->repoItems->setText(itemsCounterString + " Elements");
}


//set image filter
void MainWindow::on_filterImagesButton_clicked()
{
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    QStringList filters;
    //extend filter
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.gif" << "*.bmp" << "*.tif" << "*.ico" <<  "*.psd" << "*.pbm" <<  "*.msp" << "*.kdc" << "*.jng" << "*.jp2" << "*.img";

    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);

    ui->imageList->setRootIndex(fileModel->setRootPath(absolut));
}

//set video filter
void MainWindow::on_filterVideoButton_clicked()
{
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    QStringList filters;
    //extend filter
    filters << "*.mp4" << "*.mkv" << "*.avi" << "*.mov" << "*.mpg" << "*.wmv" << "*.mpg" << "*.flv";

    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);

    ui->imageList->setRootIndex(fileModel->setRootPath(absolut));
}

//set doc filter
void MainWindow::on_filterDocumentsButton_clicked()
{
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    QStringList filters;
    //extend filter
    filters << "*.pdf" << "*.doc" << "*.txt" << "*.html";
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);

    ui->imageList->setRootIndex(fileModel->setRootPath(absolut));
}

//search file
void MainWindow::on_searchButton_clicked()
{
    QString searchString = ui->searchInput->text();

    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    QStringList filters;
    //extend filter
    filters << "*" + searchString;
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);

    ui->imageList->setRootIndex(fileModel->setRootPath(absolut));

}

void MainWindow::on_collectionOpen_clicked()
{
    ui->imageList->setModel(fileModel);

    QDir directory = QDir::home();
    QString path = directory.path() + "/.vemoria";
    ui->imageList->setRootIndex(fileModel->setRootPath(path));

}

void MainWindow::on_openFileBtn_clicked()
{
    QtGuiServices guiServices;
    guiServices.openURL(QUrl(pathFile, QUrl::TolerantMode));
}

void MainWindow::on_deleteBtn_clicked()
{
    QtGuiServices guiServices;
    guiServices.deleteURL(QUrl(pathFile,QUrl::TolerantMode));

    //check if for illegal expression
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";
    ui->imageList->setRootIndex(fileModel->setRootPath(absolut));

    CollectionManager collmanager;
    collmanager.commit(collectionName, defaultName, defaultMail, defaultMessage);

}
