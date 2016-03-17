#include "showcollectiondialog.h"
#include "ui_showcollectiondialog.h"

showCollectionDialog::showCollectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showCollectionDialog)
{
    ui->setupUi(this);
}

showCollectionDialog::~showCollectionDialog()
{
    delete ui;
}
