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
#include <QTextEdit>
#include <QLabel>

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

    void on_openFileBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::MainWindow *ui;

    bool trigger;

    QFileSystemModel *dirModel;

    QFileSystemModel *fileModel;

    void countItems(QString path, QString collectionPath);

    void countItems2(QString path);

    void countRepos();

    QString pathFile;

    QString nameFile;

    QString collectionName;

    QString currentPath;

    QString xmlPath;

    void countRepoItems();

    QString defaultName = "defaultName";

    QString defaultMail = "infxxx@hs-worms.de";

    QString defaultMessage = "defaultMessage";

    //Datatype information
    QString description="emptee";

    //Textboxes
    QLabel *lbl_title = new QLabel();
    QTextEdit* tb_title = new QTextEdit();
    QLabel *lbl_date = new QLabel();
    QTextEdit* tb_date = new QTextEdit();
    QLabel *lbl_time = new QLabel();
    QTextEdit* tb_time = new QTextEdit();
    QLabel *lbl_geoposition = new QLabel();
    QTextEdit* tb_geoposition = new QTextEdit();
    QLabel *lbl_description = new QLabel();
    QTextEdit* tb_description = new QTextEdit();
    QLabel *lbl_creator = new QLabel();
    QTextEdit* tb_creator = new QTextEdit();
    QLabel *lbl_license = new QLabel();
    QTextEdit* tb_license = new QTextEdit();
    QLabel *lbl_people = new QLabel();
    QTextEdit* tb_people = new QTextEdit();
    QLabel *lbl_events = new QLabel();
    QTextEdit* tb_events = new QTextEdit();
    QLabel *lbl_locations = new QLabel();
    QTextEdit* tb_locations = new QTextEdit();


protected:
 void resizeEvent(QResizeEvent *e);

};

#endif // MAINWINDOW_H
