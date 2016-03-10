#include "popupcollection.h"
#include "ui_popupcollection.h"
#include "repository/collectionmanager.h"

popupCollection::popupCollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popupCollection)
{
    ui->setupUi(this);
}

popupCollection::~popupCollection()
{
    delete ui;
}

void popupCollection::on_pushButton_clicked()
{
    QString nameString = ui->lineEdit->text();

    CollectionManager collman;
    collman.createCollection(nameString);

    this->close();
}

void popupCollection::on_pushButton_2_clicked()
{
    this->close();
}
