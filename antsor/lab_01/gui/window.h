#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "../lib/action.h"

extern std::vector<QPoint> lines;

ErrorType addLine(double x1, double y1, double x2, double y2);

void showError(const ErrorType error);

void showError(QString str);

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
	
	void performAction(const ActionType action, const ParameterType param,
					   bool toDraw = true);
	
protected:
	void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);

private slots:
	void on_loadButton_clicked();
	
	void on_saveButton_clicked();
	
	void on_axisXRadio_released();
	
	void on_axisYRadio_released();
	
	void on_axisZRadio_released();
	
	void on_moveButton_clicked();
	
	void on_scaleButton_clicked();
	
	void on_rotateButton_clicked();
	
private:
    Ui::Window *ui;
};

#endif // WINDOW_H
