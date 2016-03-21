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
    ui->countItemsLabel->hide();

    trigger = false;
    addTags();

    QPixmap pixHome(":/icons/icons/home.png");
    ui->backBtn->setIcon(pixHome);

    fileModel = new QFileSystemModel(this);

    ui->listView->setModel(fileModel);

    QDir directory = QDir::home();
    if(!QDir(directory.path() + "/.vemoria").exists()){
        directory.mkdir(".vemoria");
    }

    QString path = directory.path() + "/.vemoria";
    ui->listView->setRootIndex(fileModel->setRootPath(path));

    ui->collectionOpen->hide();

    countRepos();
    countRepoItems();

}

void MainWindow::countRepos(){

    QDir directory = QDir::home();
    QString path = directory.path() + "/.vemoria";

    if(QDir(path).exists()){

        QDir dir( directory.path() + "/.vemoria" );

        dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );

        int total_files = dir.count();

        QString itemsCounterString = QString::number(total_files);

        ui->countItemsLabel->setText(itemsCounterString);

        if(total_files > 3){
            ui->collectionOpen->show();
        }
    }
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

    countRepos();
}

//count items in the contentWindow & show path
void MainWindow::countItems(QString path, QString collectionPath){

    //int counter = 0;

    //    //extend filter
    //    QDirIterator it(path, QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    //    while (it.hasNext()) {
    //        it.next();
    //        counter++;
    //    }

    //    QString itemsCounterString = QString::number(counter);

    //    ui->countItemsLabel->setText(itemsCounterString);

    //    QDir collectionName (collectionPath);

    QDir dir(path);

    qDebug() << "get path: " + path;

    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );

    int total_files = dir.count();

    QString itemsCounterString = QString::number(total_files);

    ui->countItemsLabel->setText(itemsCounterString);

    ui->pathLabel->setText(collectionPath + "/");
}

void MainWindow::countItems2(QString path){

    int counter = 0;

    //extend filter
    QDirIterator it(path, QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        counter++;
    }

    //QDir countFiles (path);

    QString itemsCounterString = QString::number(counter);

    ui->countItemsLabel->setText(itemsCounterString);
}

//show files in contentWindow
void MainWindow::on_listView_clicked(const QModelIndex &index)
{

    ui->imageList->setModel(fileModel);

    QString mPath = fileModel->fileInfo(index).absoluteFilePath();
    currentPath = mPath;

    QDir dirName = mPath;
    QString dirNameString = dirName.dirName();

    collectionName = dirNameString;

    countItems(mPath, collectionName);

    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);

    ui->imageList->setRootIndex(fileModel->setRootPath(mPath));
}


//show file in detail bar
void MainWindow::on_imageList_clicked(const QModelIndex &index)
{
    ui->formLayout_2->removeWidget(lbl_title);
    ui->formLayout_2->removeWidget(tb_title);
    ui->formLayout_2->removeWidget(lbl_date);
    ui->formLayout_2->removeWidget(tb_date);
    ui->formLayout_2->removeWidget(lbl_time);
    ui->formLayout_2->removeWidget(tb_time);
    ui->formLayout_2->removeWidget(lbl_geoposition);
    ui->formLayout_2->removeWidget(tb_geoposition);
    ui->formLayout_2->removeWidget(lbl_description);
    ui->formLayout_2->removeWidget(tb_description);
    ui->formLayout_2->removeWidget(lbl_creator);
    ui->formLayout_2->removeWidget(tb_creator);
    ui->formLayout_2->removeWidget(lbl_license);
    ui->formLayout_2->removeWidget(tb_license);
    ui->formLayout_2->removeWidget(lbl_people);
    ui->formLayout_2->removeWidget(tb_people);
    ui->formLayout_2->removeWidget(lbl_events);
    ui->formLayout_2->removeWidget(tb_events);
    ui->formLayout_2->removeWidget(lbl_locations);
    ui->formLayout_2->removeWidget(tb_locations);


    QString mPath = fileModel->fileInfo(index).absoluteFilePath();
    currentPath = mPath;
    QString xmlPath;
    xmlPath = fileModel->fileInfo(index).absolutePath();
    xmlPath+= "/.";
    xmlPath+= fileModel->fileInfo(index).fileName();

    xmlPath+= ".xml";
//qDebug() << "XML:" << xmlPath;

    QFileInfo filetester (mPath);

    bool  trueDir =   filetester.isDir();

    if(trueDir == false){
        QFileInfo file(mPath);

        QString suffix  =  file.suffix();

        if(suffix == "png" || suffix == "jpg" || suffix == "jpeg" || suffix == "bmp" || suffix == "jng" || suffix == "jp2" || suffix  == "img"){

            Picture * picture = new Picture();
            XMLHandler xmlhandler;
            picture = xmlhandler.readXMLFile_Picture(xmlPath);
            description = picture->getDescription();

            //Write values of the xml-file into the textboxes
            lbl_title->setText("Title");
            tb_title->setText(picture->getTitle());

            lbl_date->setText("Date");
            tb_date->setText(picture->getDate());

            lbl_time->setText("Time");
            tb_time->setText(picture->getTime());

            lbl_geoposition->setText("Geoposition");
            tb_geoposition->setText(picture->getGeoposition());

            lbl_description->setText("Description");
            tb_description->setText(picture->getDescription());

            lbl_creator->setText("Creator");
            tb_creator->setText(picture->getCreator());

            lbl_license->setText("License");
            tb_license->setText(picture->getLicense());

            lbl_people->setText("People");
            QString people="";
            for (int i = 0; i < picture->getPeople().count();i++)
            {
                people += picture->getPeople().at(i);
                people += "\n";
                //qDebug() << "Anzahl for:" << i << endl;
            }
            tb_people->setText(people);

            lbl_events->setText("Events");
            QString events="";
            for (int i = 0; i < picture->getEvent().count();i++)
            {
                events += picture->getEvent().at(i);
                events += "\n";
                //qDebug() << "Anzahl for:" << i << endl;
            }
            tb_events->setText(events);

            lbl_locations->setText("Locations");
            QString locations="";
            for (int i = 0; i < picture->getLocation().count();i++)
            {
                locations += picture->getLocation().at(i);
                locations += "\n";
                //qDebug() << "Anzahl for:" << i << endl;
            }
            tb_locations->setText(locations);


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
            ui->formLayout_2->addWidget(lbl_events);
            ui->formLayout_2->addWidget(tb_events);
            ui->formLayout_2->addWidget(lbl_locations);
            ui->formLayout_2->addWidget(tb_locations);









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

        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);

        //warning no subdirs
        //QString newPath = mPath + "/files";
        countItems2(mPath);

        ui->imageList->setRootIndex(fileModel->setRootPath(mPath));
    }

    QDir directory = QDir::home();
    QString homePath = directory.path() + "/.vemoria";

    if(homePath == currentPath){

        QPixmap pixHome(":/icons/icons/home.png");
        ui->backBtn->setIcon(pixHome);

         qDebug() << "home: " + currentPath;

    }
    else{
        qDebug() << "back: " + currentPath;

        QPixmap pixBack(":/icons/icons/back.png");
        ui->backBtn->setIcon(pixBack);

    }
}

//save file changes
void MainWindow::on_saveBtn_clicked()
{
    //check if for illegal expression
    QFileInfo info = (pathFile);
    QString absolut = info.absolutePath();
    absolut = absolut + "/";

    Picture *picture = new Picture();

    QString title = tb_title->toPlainText();
    QString date = tb_date->toPlainText();
    QString time = tb_time->toPlainText();
    QString geoposition = tb_geoposition->toPlainText();
    QString description = tb_description->toPlainText();
    QString creator = tb_creator->toPlainText();
    QString license = tb_license->toPlainText();

    QString people =tb_people->toPlainText();
    QStringList peoplelist = people.split("\n",QString::SkipEmptyParts);
    QVector <QString> peoplevector;
    for (int i = 0; i<peoplelist.count();i++)
    {
        peoplevector.append(peoplelist.at(i));
    }

    QString event =tb_events->toPlainText();
    QStringList eventlist = event.split("\n",QString::SkipEmptyParts);
    QVector <QString> eventvector;
    for (int i = 0; i<eventlist.count();i++)
    {
        eventvector.append(eventlist.at(i));
    }

    QString location =tb_locations->toPlainText();
    QStringList locationlist = location.split("\n",QString::SkipEmptyParts);
    QVector <QString> locationvector;
    for (int i = 0; i<locationlist.count();i++)
    {
        locationvector.append(locationlist.at(i));
    }

    picture->setTitle(title);
    picture->setDate(date);
    picture->setTime(time);
    picture->setGeoposition(geoposition);
    picture->setDescription(description);
    picture->setCreator(creator);
    picture->setLicense(license);
    picture->setPeople(peoplevector);
    picture->setEvent(eventvector);
    picture->setLocation(locationvector);



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

void MainWindow::on_backBtn_clicked()
{

    QDir directory = QDir::home();
    QString homePath = directory.path() + "/.vemoria";
    QDir homeDir (homePath);

    QStringList collectionNames = homeDir.entryList( QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden);

    foreach (const QString &collectionName, collectionNames){

       qDebug() << "foreach: default " + homePath + "/" + collectionName;
        qDebug() << "foreach: current " + currentPath;

       if(homePath + "/" + collectionName == currentPath){

        QPixmap pixHome(":/icons/icons/home.png");
        ui->backBtn->setIcon(pixHome);
       }
    }

    if(homePath == currentPath){

        QPixmap pixHome(":/icons/icons/home.png");
        ui->backBtn->setIcon(pixHome);

        qDebug() << "home: " + currentPath + "/" + collectionName;

        countItems2(currentPath);

    }
    else{
        qDebug() << "back: " + currentPath;

        //QPixmap pixBack(":/icons/icons/back.png");
        //ui->backBtn->setIcon(pixBack);

        QDir dir (currentPath);

        dir.cdUp();

        currentPath = dir.path();

        countItems2(currentPath + "/");

        ui->imageList->setModel(fileModel);

        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);

        ui->imageList->setRootIndex(fileModel->setRootPath(dir.path()));
    }

}
