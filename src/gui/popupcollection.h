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
