#ifndef COPYDIALOG_H
#define COPYDIALOG_H

#include <QDialog>
#include <QFileInfo>

namespace Ui {
class copyDialog;
}

class copyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit copyDialog(QWidget *parent = 0);
    ~copyDialog();
    void setData(const QString &labelText, const QString &dirName);
    QString path;
    QString dirPath;
    QString dirName;

private slots:
    void on_pushButton_clicked();

private:
    Ui::copyDialog *ui;

    quint64 calculateDataRate(quint64 size);
    void showDataRate(quint64 currentByte);
    bool copyDir(QString sourcePath, QString targetPath, quint64 size);
    quint64 dir_size(QString path);
    quint64 file_size(QString path);
    quint64 stackSize;
    int itemsCounter;
    void startCopy();
    bool bullshit;

};

#endif // COPYDIALOG_H
