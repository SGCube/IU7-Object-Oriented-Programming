#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

#include "controller.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit Window(ElevatorController& ctrl, QWidget *parent = nullptr);
	~Window();
	
public slots:
	void showCurrentFloor(int floor);
	void showMsg(const char* msg);
	
private slots:
	void on_pushButton_1_clicked();
	
	void on_pushButton_2_clicked();
	
	void on_pushButton_3_clicked();
	
	void on_pushButton_4_clicked();
	
	void on_pushButton_5_clicked();
	
	void on_pushButton_6_clicked();
	
	void on_pushButton_7_clicked();
	
	void on_pushButton_8_clicked();
	
	void on_pushButton_9_clicked();
	
	void on_pushButton_10_clicked();
	
	void on_openButton_clicked();
	
	void on_closeButton_clicked();
	
private:
	Ui::Window *ui;
	ElevatorController& controller;
};

#endif // WINDOW_H
