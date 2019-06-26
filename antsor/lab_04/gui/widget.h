#ifndef WIDGET_H
#define WIDGET_H

#include "../ui_widget.h"
#include "../actions/action.h"
#include "../facade/mediator.h"
#include "../exception/exceptionbase.h"
#include "drawer.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFileDialog>

#include <iostream>
#include <memory>
#include <cmath>

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
    void setUpCanvas();
    void updateCanvas();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_loadButton_clicked();
    void on_cameraBox_currentIndexChanged(int index);

	void on_moveButton_clicked();
	void on_scaleButton_clicked();
	void on_rotateButton_clicked();
	void on_rotateCButton_clicked();
	
private:
    Ui::Widget *ui;

    static constexpr double offset = 10;
    static constexpr double scaleCoeff = 2;
    static constexpr double angle = 2 * M_PI / 180;

    QGraphicsScene* canvas;
    Mediator actionController;
};

#endif // WIDGET_H
