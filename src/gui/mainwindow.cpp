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
//delete?
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

            //Title
            QLabel *lbl_title = new QLabel();
            lbl_title->setText("Title");
            QTextEdit* tb_title = new QTextEdit();
            tb_title->setText(picture->getTitle());

            QLabel *lbl_date = new QLabel();
            lbl_date->setText("Date");
            QTextEdit* tb_date = new QTextEdit();
            tb_date->setText(picture->getDate());

            QLabel *lbl_time = new QLabel();
            lbl_time->setText("Time");
            QTextEdit* tb_time = new QTextEdit();
            tb_time->setText(picture->getTime());

            QLabel *lbl_geoposition = new QLabel();
            lbl_geoposition->setText("Geoposition");
            QTextEdit* tb_geoposition = new QTextEdit();
            tb_geoposition->setText(picture->getGeoposition());

            QLabel *lbl_description = new QLabel();
            lbl_description->setText("Description");
            QTextEdit* tb_description = new QTextEdit();
            tb_description->setText(picture->getDescription());

            QLabel *lbl_creator = new QLabel();
            lbl_creator->setText("Creator");
            QTextEdit* tb_creator = new QTextEdit();
            tb_creator->setText(picture->getCreator());

            QLabel *lbl_license = new QLabel();
            lbl_license->setText("License");
            QTextEdit* tb_license = new QTextEdit();
            tb_license->setText(picture->getLicense());

            QLabel *lbl_people = new QLabel();
            lbl_people->setText("People");
            QTextEdit* tb_people = new QTextEdit();
            QString people="";

            //QString blub = picture->getPeople().count();
//            QByteArray =
            qDebug() << "Anzahl people:" << QString::number(picture->getPeople().count()) << endl;

            for (int i = 0; i < picture->getPeople().count();i++)
            {
                people += picture->getPeople().at(i);
                people += "\n";
                //qDebug() << "Anzahl for:" << i << endl;
            }
            tb_people->setText(people);
            qDebug() << "People" << people << endl;

//            QLabel *lbl_events = new QLabel();
//            lbl_events->setText("Events");
//            QTextEdit* tb_events = new QTextEdit();
//            tb_events->setText(people);

//            QLabel *lbl_locations = new QLabel();
//            lbl_locations->setText("Locations");
//            QTextEdit* tb_locations = new QTextEdit();
//            tb_locations->setText(people);


            ui->formLayout_2->addWidget(lbl_title);
            ui->formLayout_2->addWidget(tb_title);
            ui->formLayout_2->addWidget(lbl_date);
            ui->formLayout_2->addWidget(tb_date);
            ui->formLayout_2->addWidget(lbl_time);
            ui->formLayout_2->addWidget(tb_time);
            ui->formLayout_2->addWidget(lbl_geoposition);
            ui->formLayout_2->addWidget(tb_geoposition);
            ui->formLayout_2->addWidget(lbl_description);
            ui->formLayout_2->addWidget(tb_description);
            ui->formLayout_2->addWidget(lbl_creator);
            ui->formLayout_2->addWidget(tb_creator);
            ui->formLayout_2->addWidget(lbl_license);
            ui->formLayout_2->addWidget(tb_license);
            ui->formLayout_2->addWidget(lbl_people);
            ui->formLayout_2->addWidget(tb_people);
//            ui->formLayout_2->addWidget(lbl_events);
//            ui->formLayout_2->addWidget(tb_events);
//            ui->formLayout_2->addWidget(lbl_locations);
//            ui->formLayout_2->addWidget(tb_locations);



//            QVector<QTextEdit> lineedits;
//            //QVector<QTextEdit> *lineedits;
//            for (int i = 0; i<picture->getPeople().count();i++)
//            {

//                QTextEdit *lines = new QTextEdit();
//                lines->setText(picture->getPeople().at(i));

//                ui->formLayout_2->addWidget(lines);




//                //lineedits.append(new QTextEdit());


////                lineedits->at(i)= lines;
//                //lines = lineedits->at(i);
//            }

//            ui->formLayout_2->addWidget(label);
//            ui->formLayout_2->addWidget(lineedit);

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
