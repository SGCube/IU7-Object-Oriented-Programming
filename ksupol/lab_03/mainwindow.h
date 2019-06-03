#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "lift.h"

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
    void on_to_1_clicked();

    void on_to_2_clicked();

    void on_to_3_clicked();

    void on_to_4_clicked();

    void on_to_5_clicked();

    void on_to_6_clicked();

    void on_call_1_clicked();

    void on_call_2_clicked();

    void on_call_3_clicked();

    void on_call_4_clicked();

    void on_call_5_clicked();

    void on_call_6_clicked();

private:
    Ui::MainWindow *ui;
    Lift lift;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
