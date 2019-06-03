#include "window.h"
#include "ui_window.h"

Window::Window(ElevatorController& ctrl, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Window),
	controller(ctrl)
{
	ui->setupUi(this);
	
	connect(this, SIGNAL(pushButton(int)), &controller, SLOT(onPushButton(int)));
	connect(&controller, SIGNAL(pullButton(int)), this, SLOT(pullButton(int)));
	
	// messages
	connect(&controller, SIGNAL(showCurFloor(int)),
			this, SLOT(getCurrentFloor(int)));
    connect(&controller, SIGNAL(showMessage(const char*)),
			this, SLOT(getMsg(const char*)));
}

Window::~Window()
{
	buttons.clear();
	delete ui;
}

void Window::pullButton(int floor)
{
	QPushButton* btn = getButton(floor);
	if (btn)
		btn->setEnabled(true);
}

void Window::getCurrentFloor(int floor)
{
	ui->floorScreen->display(floor);
}

void Window::getMsg(const char* msg)
{
	ui->msgScreen->setText(QString(msg));
}

void Window::on_pushButton_1_clicked()
{
	ui->pushButton_1->setEnabled(false);
	emit pushButton(1);
}

void Window::on_pushButton_2_clicked()
{
	ui->pushButton_2->setEnabled(false);
	emit pushButton(2);
}

void Window::on_pushButton_3_clicked()
{
	ui->pushButton_3->setEnabled(false);
	emit pushButton(3);
}

void Window::on_pushButton_4_clicked()
{
	ui->pushButton_4->setEnabled(false);
	emit pushButton(4);
}

void Window::on_pushButton_5_clicked()
{
	ui->pushButton_5->setEnabled(false);
	emit pushButton(5);
}

void Window::on_pushButton_6_clicked()
{
	ui->pushButton_6->setEnabled(false);
	emit pushButton(6);
}

void Window::on_pushButton_7_clicked()
{
	ui->pushButton_7->setEnabled(false);
	emit pushButton(7);
}

void Window::on_pushButton_8_clicked()
{
	ui->pushButton_8->setEnabled(false);
	emit pushButton(8);
}

void Window::on_pushButton_9_clicked()
{
	ui->pushButton_9->setEnabled(false);
	emit pushButton(9);
}

void Window::on_pushButton_10_clicked()
{
	ui->pushButton_10->setEnabled(false);
	emit pushButton(10);
}

QPushButton* Window::getButton(int floor)
{
	switch(floor)
	{
		case 1:
			return ui->pushButton_1;
		case 2:
			return ui->pushButton_2;
		case 3:
			return ui->pushButton_3;
		case 4:
			return ui->pushButton_4;
		case 5:
			return ui->pushButton_5;
		case 6:
			return ui->pushButton_6;
		case 7:
			return ui->pushButton_7;
		case 8:
			return ui->pushButton_8;
		case 9:
			return ui->pushButton_9;
		case 10:
			return ui->pushButton_10;
	}
	return nullptr;
}
