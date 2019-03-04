#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    int ac = file_work(str);
    qDebug() << ac;
}
