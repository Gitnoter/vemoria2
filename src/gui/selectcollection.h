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

private:
    Ui::selectCollection *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
};

#endif // SELECTCOLLECTION_H
