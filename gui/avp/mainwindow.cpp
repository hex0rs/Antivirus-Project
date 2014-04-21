#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMovie>
#include <QSize>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/scan.png); border: none;}""QPushButton:hover {background-image: url(:/new/prefix1/scanh.png); border: none;}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/quar.png); border: none;}""QPushButton:hover {background-image: url(:/new/prefix1/quarh.png); border: none;}");
    ui->pushButton_3->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/setting.png); border: none;}""QPushButton:hover {background-image: url(:/new/prefix1/settingh.png); border: none;}");
    ui->pushButton_4->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/close.png); border: none;}""QPushButton:hover {background-image: url(:/new/prefix1/closeh.png); border: none;}");
    ui->pushButton_5->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/min.png); border: none;}""QPushButton:hover {background-image: url(:/new/prefix1/minh.png); border: none;}");


    QMovie *movie = new QMovie(":/new/prefix1/cir.gif");
    QSize csi(300,300);
    movie->setScaledSize(csi);
    ui->label_2->setMovie(movie);
    movie->start();
    ui->label_2->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    destroy();
}

void MainWindow::on_pushButton_5_clicked()
{
    showMinimized();
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
        /*
        QString fileName = QFileDialog::getOpenFileName(this);
        */
        if (!fileNames.isEmpty())

            ui->label->hide();
            ui->label_2->show();

            //ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/cir.gif);");
            //for(qint32 a=0;a<fileNames.size();a++)
            //ui->label_2->setText(fileNames[a]);

}
