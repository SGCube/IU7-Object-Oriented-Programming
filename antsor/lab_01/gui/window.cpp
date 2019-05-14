#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "window.h"
#include "../ui_window.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QCloseEvent>

#define CENTER 360
#define BORDER (CENTER * 2)
#define TO_CENTER(x) (x + CENTER)

ErrorType addLine(double x1, double y1, double x2, double y2)
{
    QPoint startPoint(TO_CENTER(x1), TO_CENTER(y1));
	QPoint endPoint(TO_CENTER(x2), TO_CENTER(y2));
	lines.push_back(startPoint);
    lines.push_back(endPoint);
    return OK;
}

void showError(const ErrorType error)
{
    QMessageBox::critical(NULL, "Error", getErrorMsg(error));
}

void showError(QString str)
{
    QMessageBox::critical(NULL, "Error", str);
}

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
	pointsAmount = 0;
	pointsToDraw = nullptr;
	repaint();
}

Window::~Window()
{
    delete ui;
}

void Window::closeEvent(QCloseEvent *event)
{
	Q_UNUSED(event);
	ParameterType param;
	ErrorType error = actionFunc(ACTION_FREE, param);
	if (error != OK)
		showError(error);
}

void Window::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	
    QPainter painter(this);
	QPen axisPen(Qt::gray);
	QPen modelPen(Qt::black);
	
	painter.fillRect(0, 0, BORDER, BORDER, Qt::white);
	
    painter.setPen(axisPen);
    painter.drawLine(0, CENTER, BORDER, CENTER);
    painter.drawLine(CENTER, 0, CENTER, BORDER);
    painter.drawLine(BORDER, 0, 0, BORDER);
	

    painter.setPen(modelPen);
    for (size_t i = 0; i < pointsAmount; i += 2)
	{
        painter.drawLine(pointsToDraw[i][0], pointsToDraw[i][1],
						 pointsToDraw[i + 1][0], pointsToDraw[i + 1][1]);
	}
}

void Window::performAction(const ActionType action, ParameterType param,
						   bool toDraw)
{
	ErrorType error = actionFunc(action, param);
	if (error != OK)
    {
        showError(error);
        return;
    }

	if (toDraw)
	{
		ParameterType paramDraw;
		paramDraw.drawParameters.pointsToDraw = pointsToDraw;
		paramDraw.drawParameters.pointsAmount = &pointsAmount;
		
		error = actionFunc(ACTION_DRAW, paramDraw);
		if (error != OK)
		{
			showError(error);
			return;
		}
		repaint();
		if (pointsToDraw)
			free(pointsToDraw);
		pointsAmount = 0;
	}
}

void Window::on_loadButton_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Load model", "",
													"Model Data (*.txt)");
    if (filePath.isEmpty())
        return;

    ParameterType param;
	std::string str = filePath.toStdString();	
    param.fileWorkParameters.fileName = str.c_str();
	
    performAction(ACTION_LOAD, param, true);
}

void Window::on_saveButton_clicked()
{
	QString filePath = QFileDialog::getSaveFileName(this, "Save model", "",
													"Model Data (*.txt)");
    if (filePath.isEmpty())
        return;

    ParameterType param;
	std::string str = filePath.toStdString();	
	param.fileWorkParameters.fileName = str.c_str();
	
	performAction(ACTION_SAVE, param, false);
}

void Window::on_axisXRadio_released()
{
    ui->axisYRadio->setChecked(false);
	ui->axisZRadio->setChecked(false);
}

void Window::on_axisYRadio_released()
{
	ui->axisXRadio->setChecked(false);
	ui->axisZRadio->setChecked(false);
}

void Window::on_axisZRadio_released()
{
	ui->axisXRadio->setChecked(false);
	ui->axisYRadio->setChecked(false);
}

void Window::on_moveButton_clicked()
{
	double dx = ui->dxSpinbox->value();
    double dy = ui->dySpinbox->value();
    double dz = ui->dzSpinbox->value();

    ParameterType param;
    param.moveParameters.dx = dx;
    param.moveParameters.dy = dy;
    param.moveParameters.dz = dz;
	
	performAction(ACTION_MOVE, param, true);
}

void Window::on_scaleButton_clicked()
{
	/// coeffs
	
	double kx = ui->kxSpinbox->value();
    double ky = ui->kySpinbox->value();
    double kz = ui->kzSpinbox->value();
	
	/// center coords
	
	double xc = ui->cxSpinbox->value();
    double yc = ui->cySpinbox->value();
    double zc = ui->czSpinbox->value();

    ParameterType param;
	param.scaleParameters.kx = kx;
    param.scaleParameters.ky = ky;
    param.scaleParameters.kz = kz;
    param.scaleParameters.xc = xc;
    param.scaleParameters.yc = yc;
    param.scaleParameters.zc = zc;
	
    performAction(ACTION_SCALE, param, true);
}

void Window::on_rotateButton_clicked()
{
	double xc = ui->cxSpinbox->value();
    double yc = ui->cySpinbox->value();
    double zc = ui->czSpinbox->value();
	int angle = ui->angleSpinbox->value();
	
	AxisType axis;
    if (ui->axisXRadio->isChecked())
        axis = X;
    else if (ui->axisYRadio->isChecked())
        axis = Y;
    else
        axis = Z;

    ParameterType param;
	param.rotateParameters.angle = angle;
	param.rotateParameters.axis = axis;
	param.rotateParameters.xc = xc;
    param.rotateParameters.yc = yc;
    param.rotateParameters.zc = zc;
	
    performAction(ACTION_ROTATE, param, true);
}

void Window::on_projectButton_clicked()
{
	ParameterType param;
	ActionType action;
	
	AxisType axis;
    if (ui->axisXRadio->isChecked())
        axis = X;
    else if (ui->axisYRadio->isChecked())
        axis = Y;
    else
        axis = Z;
	
	if (ui->projectBox->currentIndex() == 0)
	{
		param.projParallelParameters.axis = axis;
		action = ACTION_PROJECT_PARALLEL;
	}
	else
	{
		param.projCentralParameters.axis = axis;
		param.projCentralParameters.distance = ui->dSpinbox->value();
		action = ACTION_PROJECT_CENTRAL;
	}
	
	performAction(action, param, true);
}

void Window::on_projectBox_currentIndexChanged(int index)
{
    ui->dSpinbox->setEnabled((index == 1));
}

#endif // WINDOW_CPP
