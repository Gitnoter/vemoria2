#include "copydialog.h"
#include "ui_copydialog.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <copydialog.h>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <timer.h>
#include <qapplication.h>

copyDialog::copyDialog(QWidget *parent) : QDialog(parent), ui(new Ui::copyDialog)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

copyDialog::~copyDialog()
{
    delete ui;
}

void copyDialog::on_pushButton_clicked()
{
    ui->progressBar->setValue(0);

    //open file explorer to select a directory
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly  | QFileDialog::DontResolveSymlinks);
    QFileInfo file(dirName);

    stackSize = 0;
    itemsCounter = 0;

    //get directory size to setup the progressBar
    qint64 size =  dir_size(dirName);
    ui->progressBar->setMaximum(size);

    //start copying files
    bool copy = copyDir(dirName, "C:/Users/Dennis/Desktop/" + file.fileName(), size);

    ui->pathLabel->setText("Copying items from " + dirName + " to C:/Users/");

    if(copy == true){
        ui->progressBar->setMaximum(100);
        ui->progressBar->setValue(100);
        ui->speedLabel->setText("Data rate: 0 kb/s");
        QMessageBox::information(this, tr("File Name"), dirName);
    }
}

//copying files
bool copyDialog::copyDir(QString sourcePath, QString targetPath, quint64 size)
{
    QFileInfo srcFileInfo(sourcePath);
    if (srcFileInfo.isDir()) {
        QDir targetDir(targetPath);

        //cd in the selected directory
        targetDir.cdUp();
        if (!targetDir.mkdir(QFileInfo(targetPath).fileName()))
            return false;
        QDir sourceDir(sourcePath);
        QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);

        foreach (const QString &fileName, fileNames) {


            //get source & target path of copied files
            const QString newSrcFilePath = sourcePath + QLatin1Char('/') + fileName;
            const QString newTgtFilePath = targetPath + QLatin1Char('/') + fileName;


            //get file size to calculate speed & process status
            quint64 fileSize = file_size(newSrcFilePath);

            timer time;
            int speed = time.MySlot(fileSize);

            //calculate current copyied files in bytes
            stackSize = fileSize + stackSize;
            showDataRate(stackSize);

            QString speedString = QString::number(speed);
            QString itemsCounterString = QString::number(itemsCounter);

            ui->speedLabel->setText("Data rate: " + speedString + " kb/s");
            ui->copiedItemsLabel->setText("Items copied: " + itemsCounterString);

            quint64 hundert = 100;

            //calculate current process status in %
            quint64 procent = (stackSize * hundert) / size;
            QString procentString = QString::number(procent);

            ui->procentLabel->setText(procentString +"% complete");
            ui->itemsNameLabel->setText(newSrcFilePath);
            ui->progressBar->setValue(stackSize);

            //count items that are copied
            itemsCounter++;

            //gui not freezing function
            qApp->processEvents();

            if(!copyDir(newSrcFilePath, newTgtFilePath, size))
                return false;
        }
    } else {
        if (!QFile::copy(sourcePath, targetPath))
            return false;
    }
    return true;
}

//calculate size of copied directory
quint64 copyDialog::dir_size(QString path)
{
    quint64 sizex = 0;
    QFileInfo str_info(path);
    if (str_info.isDir())
    {
        QDir dir(path);

        //get a list of files in the current directory
        QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs |  QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isDir())
            {
                sizex += dir_size(fileInfo.absoluteFilePath());
            }
            else
                //add the size of the current file
                sizex += fileInfo.size();
        }
    }
    return sizex;
}

//calculate size of current copied files
quint64 copyDialog::file_size(QString path){

    quint64 size = 0;

    QFileInfo file(path);

    size = file.size();

    return size;
}

quint64 copyDialog::calculateDataRate(quint64 size){

    quint64 kilobyte = size / 1024;
    quint64 megabyte = kilobyte / 1024;

    return megabyte;

}

//show copied bytes
void copyDialog::showDataRate(quint64 currentBytes){

    quint64 currentMb = calculateDataRate(currentBytes);
    QString currentMbString = QString::number(currentMb);

    ui->bytesLabel->setText("Total Bytes: " + currentMbString + " kb");
}
