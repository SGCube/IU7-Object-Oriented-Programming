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

std::vector<QPoint> lines;

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
    ui(new Ui::Window),
	scene(0, 0, BORDER, BORDER)
{
    ui->setupUi(this);
	ui->graphicsView->setScene(&scene);
}

Window::~Window()
{
    delete ui;
}

void Window::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
	QImage img(BORDER, BORDER, QImage::Format_RGB32);
    QPainter painter(&img);
	QPen axisPen(Qt::gray);
	QPen modelPen(Qt::black);

    painter.setPen(axisPen);
    painter.drawLine(0, CENTER, BORDER, CENTER);
    painter.drawLine(CENTER, 0, CENTER, BORDER);
    painter.drawLine(0, 0, BORDER, BORDER);

    painter.setPen(modelPen);

    for (unsigned int i = 0; i < lines.size(); i += 2)
	{
        painter.drawLine(lines[i].x(), lines[i].y(),
						 lines[i + 1].x(), lines[i + 1].y());
	}
	
	scene.addPixmap(QPixmap::fromImage(img));
}

void Window::closeEvent(QCloseEvent *event)
{
	ParameterType param;
	ErrorType error = actionFunc(ACTION_FREE, param);
	if (error != OK)
		showError(error);
}

void Window::performAction(const ActionType action, const ParameterType param,
						   bool toDraw)
{
	ErrorType error = actionFunc(action, param);
	if (error != OK)
    {
        showError(error);
        return;
    }

	if (!toDraw)
	{
		lines.clear();
		error = actionFunc(ACTION_DRAW, param);
		if (error != OK)
		{
			showError(error);
			return;
		}
		repaint();
	}
}

void Window::on_loadButton_released()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Load model", "",
													"Model Data (*.txt)");
    if (filePath.isEmpty())
    {
        showError(ERROR_FILE_NAME);
        return;
    }

    ParameterType param;
    param.fileWorkParameters.fileName = filePath.toLatin1().data();
    performAction(ACTION_LOAD, param);
}

void Window::on_saveButton_released()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Load model", "",
													"Model Data (*.txt)");
    if (filePath.isEmpty())
    {
        showError(ERROR_FILE_NAME);
        return;
    }

    ParameterType param;
    param.fileWorkParameters.fileName = filePath.toLatin1().data();
	performAction(ACTION_SAVE, param, false);
}

void Window::on_moveButton_released()
{
	QString strX = ui->dxSpinbox->text();
    QString strY = ui->dySpinbox->text();
    QString strZ = ui->dzSpinbox->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkX, checkY, checkZ;
	
    double dx = strX.toDouble(&checkX);
    double dy = strY.toDouble(&checkY);
    double dz = strZ.toDouble(&checkZ);
	
    if (!checkX || !checkY || !checkZ)
    {
        showError("Error input: wrong data");
        return;
    }

    ParameterType param;
    param.moveParameters.dx = dx;
    param.moveParameters.dy = dy;
    param.moveParameters.dz = dz;
	performAction(ACTION_MOVE, param);
}

void Window::on_scaleButton_released()
{
	/// coeffs
	
	QString strX = ui->kxSpinbox->text();
    QString strY = ui->kySpinbox->text();
    QString strZ = ui->kzSpinbox->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkX, checkY, checkZ;
	
    double kx = strX.toDouble(&checkX);
    double ky = strY.toDouble(&checkY);
    double kz = strZ.toDouble(&checkZ);
	
    if (!checkX || !checkY || !checkZ)
    {
        showError("Error input: wrong data");
        return;
    }
	
	/// center coords
	
	strX = ui->cxSpinbox->text();
    strY = ui->cySpinbox->text();
    strZ = ui->czSpinbox->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }
	
    double xc = strX.toDouble(&checkX);
    double yc = strY.toDouble(&checkY);
    double zc = strZ.toDouble(&checkZ);
	
    if (!checkX || !checkY || !checkZ)
    {
        showError("Error input: wrong data");
        return;
    }

    ParameterType param;
	param.scaleParameters.kx = kx;
    param.scaleParameters.ky = ky;
    param.scaleParameters.kz = kz;
    param.scaleParameters.xc = xc;
    param.scaleParameters.yc = yc;
    param.scaleParameters.zc = zc;
	
    performAction(ACTION_SCALE, param);
}

void Window::on_rotateButton_released()
{
	QString strX = ui->dxSpinbox->text();
    QString strY = ui->dySpinbox->text();
    QString strZ = ui->dzSpinbox->text();
	QString strA = ui->angleSpinbox->text();

    if (strX.isEmpty() || strY.isEmpty() || strZ.isEmpty() || strA.isEmpty())
    {
        showError("Error input: empty line");
        return;
    }

    bool checkX, checkY, checkZ, checkA;
	
    double xc = strX.toDouble(&checkX);
    double yc = strY.toDouble(&checkY);
    double zc = strZ.toDouble(&checkZ);
	int angle = strA.toInt(&checkA);
	
    if (!checkX || !checkY || !checkZ || !checkA)
    {
        showError("Error input: wrong data");
        return;
    }
	
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
	
    performAction(ACTION_ROTATE, param);
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

#endif // WINDOW_CPP
