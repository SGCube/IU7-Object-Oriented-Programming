#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "../lib/action.h"

extern std::vector<QPoint> lines;

ErrorType drawLine(double x1, double y1, double x2, double y2);

void showError(const ErrorType error);

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
	
protected:
	void paintEvent(QCloseEvent *event);
	void closeEvent(QCloseEvent *event);

private slots:
	void on_loadButton_released();
	
	void on_saveButton_released();
	
	void on_moveButton_released();
	
	void on_scaleButton_released();
	
	void on_rotateButton_released();
	
	void on_axisXRadio_released();
	
	void on_axisYRadio_released();
	
	void on_axisZRadio_released();
	
private:
    Ui::Window *ui;
	
	void performAction(const ActionType action, const ParameterType param,
					   bool toDraw = true);
};

#endif // WINDOW_H
