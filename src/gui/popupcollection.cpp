/// \file
/// \brief	Vemoria popupcollection cpp file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

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
