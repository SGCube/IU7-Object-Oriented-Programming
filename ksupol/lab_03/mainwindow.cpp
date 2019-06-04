#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lift.set_action_text(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_to_1_clicked()
{
    ui->textEdit->append("Пассажир нажал на первый этаж");
    lift.add_stop(1);
}

void MainWindow::on_to_2_clicked()
{
    ui->textEdit->append("Пассажир нажал на второй этаж");
    lift.add_stop(2);
}

void MainWindow::on_to_3_clicked()
{
    ui->textEdit->append("Пассажир нажал на третий этаж");
    lift.add_stop(3);
}

void MainWindow::on_to_4_clicked()
{
    ui->textEdit->append("Пассажир нажал на четвертый этаж");
    lift.add_stop(4);
}

void MainWindow::on_to_5_clicked()
{
    ui->textEdit->append("Пассажир нажал на пятый этаж");
    lift.add_stop(5);
}

void MainWindow::on_to_6_clicked()
{
    ui->textEdit->append("Пассажир нажал на шестой этаж");
    lift.add_stop(6);
}

void MainWindow::on_call_1_clicked()
{
    ui->textEdit->append("Лифт был вызван на первом этаже");
    lift.add_stop(1);
}

void MainWindow::on_call_2_clicked()
{
    ui->textEdit->append("Лифт был вызван на втором этаже");
    lift.add_stop(2);
}

void MainWindow::on_call_3_clicked()
{
    ui->textEdit->append("Лифт был вызван на третьем этаже");
    lift.add_stop(3);
}

void MainWindow::on_call_4_clicked()
{
    ui->textEdit->append("Лифт был вызван на четвертом этаже");
    lift.add_stop(4);
}

void MainWindow::on_call_5_clicked()
{
    ui->textEdit->append("Лифт был вызван на пятом этаже");
    lift.add_stop(5);
}

void MainWindow::on_call_6_clicked()
{
    ui->textEdit->append("Лифт был вызван на шестом этаже");
    lift.add_stop(6);
}
