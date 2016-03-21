/// \file
/// \brief	Vemoria selectioncollection header file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#ifndef SELECTCOLLECTION_H
#define SELECTCOLLECTION_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class selectCollection;
}

class selectCollection : public QDialog
{
    Q_OBJECT

public:
    explicit selectCollection(QWidget *parent = 0);
    ~selectCollection();

private slots:
    void on_pushButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::selectCollection *ui;
    QFileSystemModel *fileModel;
    QString selectedPath;
};

#endif // SELECTCOLLECTION_H
