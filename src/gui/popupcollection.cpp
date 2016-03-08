#include "popupcollection.h"
#include "ui_popupcollection.h"

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

}

void popupCollection::on_pushButton_2_clicked()
{
    this->close();
}
