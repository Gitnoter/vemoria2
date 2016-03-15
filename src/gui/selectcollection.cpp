#include "selectcollection.h"
#include "ui_selectcollection.h"
#include "QLabel"
#include <QDir>
#include <QLayout>
#include <QListWidgetItem>
#include <QSize>
#include <copydialog.h>

selectCollection::selectCollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectCollection)
{
        ui->setupUi(this);

        QString mPath = "C:/";
        dirModel = new QFileSystemModel(this);

        dirModel->setRootPath(mPath);

        fileModel = new QFileSystemModel(this);

        fileModel->setRootPath(mPath);

        ui->listView->setModel(fileModel);

        ui->listView->setRootIndex(fileModel->setRootPath("C:/Vemoria"));
}

selectCollection::~selectCollection()
{
    delete ui;
}

void selectCollection::on_pushButton_clicked()
{
    if(selectedPath != NULL){
        copyDialog cpyDialog;
        cpyDialog.setModal(true);
        cpyDialog.setData(selectedPath);
        cpyDialog.exec();
    }
   else{
        //message
    }
}

void selectCollection::on_listView_clicked(const QModelIndex &index)
{
          QString mPath = dirModel->fileInfo(index).absoluteFilePath();
          selectedPath = mPath;

          ui->label->setText(mPath);
}
