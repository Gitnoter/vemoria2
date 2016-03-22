/// \file
/// \brief	Vemoria selectcollection cpp file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include "selectcollection.h"
#include "ui_selectcollection.h"
#include "QLabel"
#include <QDir>
#include <QLayout>
#include <QListWidgetItem>
#include <QSize>
#include <copydialog.h>
#include <QFileDialog>

selectCollection::selectCollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectCollection)
{
        ui->setupUi(this);

        fileModel = new QFileSystemModel(this);

        ui->listView->setModel(fileModel);

        QDir directory = QDir::home();
        if(QDir(directory.path() + "/.vemoria").exists()){
                    QDir directory = QDir::home();
                    QString path = directory.path() + "/.vemoria";
                    ui->listView->setRootIndex(fileModel->setRootPath(path));
        }
        else{
            ui->listView->setRootIndex(fileModel->setRootPath(QDir::homePath()));
        }
}

selectCollection::~selectCollection()
{
    delete ui;
}

void selectCollection::on_pushButton_clicked()
{

    //open file explorer to select a directory
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly  | QFileDialog::DontResolveSymlinks);

    if(selectedPath != NULL){
        copyDialog cpyDialog;
        cpyDialog.setData(selectedPath, dirName);
        cpyDialog.setModal(true);
        cpyDialog.exec();
    }
   else{
        //message
    }
}

void selectCollection::on_listView_clicked(const QModelIndex &index)
{
          QString mPath = fileModel->fileInfo(index).absoluteFilePath();
          selectedPath = mPath;
          ui->label->setText(mPath);
}
