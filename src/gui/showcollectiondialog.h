#ifndef SHOWCOLLECTIONDIALOG_H
#define SHOWCOLLECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class showCollectionDialog;
}

class showCollectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showCollectionDialog(QWidget *parent = 0);
    ~showCollectionDialog();

private:
    Ui::showCollectionDialog *ui;
};

#endif // SHOWCOLLECTIONDIALOG_H
