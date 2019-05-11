#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QCloseEvent>

#include "../library/action.h"
#include "display_error.h"

extern std::vector <QPoint> lines;

#define CENTER 350
#define AXIS_GAP_L 10
#define AXIS_GAP_R 690
#define TO_CENTER(x) x + CENTER

using namespace std;

error_type drawLine(double x1, double y1, double x2, double y2);

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void on_OpenFile_clicked();
    void on_SaveModel_clicked();
    void on_ShiftButton_clicked();
    void on_TurnButton_clicked();
    void on_ScaleButton_clicked();
    void on_ProjectP_clicked();
    void on_ProjectC_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

