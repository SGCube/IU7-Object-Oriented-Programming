#include "window.h"
#include "ui_window.h"

Window::Window(ElevatorController& ctrl, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Window),
	controller(ctrl)
{
	ui->setupUi(this);
	
	connect(&controller, SIGNAL(doFloorShow(int)),
			this, SLOT(showCurrentFloor(int)));
    connect(&controller, SIGNAL(doMsgShow(const char*)),
			this, SLOT(showMsg(const char*)));
}

Window::~Window()
{
	delete ui;
}

void Window::showCurrentFloor(int floor)
{
	ui->floorScreen->display(floor);
}

void Window::showMsg(const char* msg)
{
	ui->msgScreen->setText(QString(msg));
}

void Window::on_pushButton_1_clicked()
{
    controller.onPushButton(1);
}

void Window::on_pushButton_2_clicked()
{
    controller.onPushButton(2);
}

void Window::on_pushButton_3_clicked()
{
    controller.onPushButton(3);
}

void Window::on_pushButton_4_clicked()
{
    controller.onPushButton(4);
}

void Window::on_pushButton_5_clicked()
{
    controller.onPushButton(5);
}

void Window::on_pushButton_6_clicked()
{
    controller.onPushButton(6);
}

void Window::on_pushButton_7_clicked()
{
    controller.onPushButton(7);
}

void Window::on_pushButton_8_clicked()
{
    controller.onPushButton(8);
}

void Window::on_pushButton_9_clicked()
{
    controller.onPushButton(9);
}

void Window::on_pushButton_10_clicked()
{
    controller.onPushButton(10);
}

void Window::on_openButton_clicked()
{
    controller.onOpenButton();
}

void Window::on_closeButton_clicked()
{
    controller.onCloseButton();
}
