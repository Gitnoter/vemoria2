#include "selectcollection.h"
#include "ui_selectcollection.h"
#include "QLabel"
#include <QDir>
#include <QLayout>
#include <QListWidgetItem>
#include <QSize>

selectCollection::selectCollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectCollection)
{
    ui->setupUi(this);

        QString mPath = "C:/Vemoria";
        dirModel = new QFileSystemModel(this);
        dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

        dirModel->setRootPath(mPath);

        fileModel = new QFileSystemModel(this);

        fileModel->setRootPath(mPath);

        ui->listView->setModel(fileModel);

        dirModel = new QFileSystemModel(this);
        fileModel = new QFileSystemModel(this);

        ui->listView->setRootIndex(dirModel->setRootPath(mPath));
}

selectCollection::~selectCollection()
{
    delete ui;
}
