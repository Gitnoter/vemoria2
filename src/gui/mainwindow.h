/// \file
/// \brief	Vemoria mainwindow header file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionNew_Collection_triggered();

    void on_deleteBtn_clicked();

    void on_saveBtn_clicked();

    void on_actionInfo_triggered();

    void on_pushButton_3_clicked();

    void addTags();

    void on_addButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_imageList_clicked(const QModelIndex &index);

    void on_filterImagesButton_clicked();

    void on_filterVideoButton_clicked();

    void on_filterDocumentsButton_clicked();

    void on_searchButton_clicked();

    void on_collectionOpen_clicked();

private:
    Ui::MainWindow *ui;

    bool trigger;

    QFileSystemModel *dirModel;

    QFileSystemModel *fileModel;

    void countItems(QString path);

    QString pathFile;

    QString nameFile;

    void countRepoItems();

protected:
 void resizeEvent(QResizeEvent *e);

};

#endif // MAINWINDOW_H
