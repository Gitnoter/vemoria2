/// \file
/// \brief	Vemoria popupcollection header file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef POPUPCOLLECTION_H
#define POPUPCOLLECTION_H

#include <QDialog>

namespace Ui {
class popupCollection;
}

class popupCollection : public QDialog
{
    Q_OBJECT

public:
    explicit popupCollection(QWidget *parent = 0);
    ~popupCollection();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::popupCollection *ui;
};

#endif // POPUPCOLLECTION_H
