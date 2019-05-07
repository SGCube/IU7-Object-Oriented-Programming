#ifndef WIDGET_CPP
#define WIDGET_CPP

#include "widget.h"
#include "../ui_widget.h"

std::vector <QPoint> lines;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    for (unsigned int i = 0; i < lines.size(); i += 2)
        painter.drawLine(lines[i].x(), lines[i].y(), lines[i + 1].x(), lines[i + 1].y());
}

void Widget::setLine(QPoint src, QPoint purp)
{
    lines.push_back(src);
    lines.push_back(purp);
}

error_type drawLine(double x1, double y1, double x2, double y2)
{
    QPoint src, purp;
    src.setX(TO_CENTER(x1));
    src.setY(TO_CENTER(y1));
    purp.setX(TO_CENTER(x2));
    purp.setY(TO_CENTER(y2));

    Widget obj;
    obj.setLine(src, purp);

    return OK;
}

void Widget::on_OpenFile_clicked()
{
    QString filePath = QFileDialog::\
            getOpenFileName(this, "Open model", "", "Wavefront (*.txt)");
    if (filePath.isEmpty())
    {
        display_error("Файл не выбран!");
        return;
    }
    actionDataType data;
    data.fileName = filePath.toLatin1().data();
    error_type error;
    if ((error = find_action(load, data)))
    {
        display_error(error);
        return;
    }
    lines.clear();
    if ((error = find_action(draw, data)))
        display_error(error);
    repaint();
}

void Widget::on_SaveModel_clicked()
{
    QString filePath = QFileDialog::\
            getOpenFileName(this, "Open model", "", "Wavefront (*.txt)");
    if (filePath == NULL)
    {
        display_error("Файл не выбран!");
        return;
    }
    actionDataType data;
    data.fileName = filePath.toLatin1().data();
    error_type error;
    if ((error = find_action(save, data)))
        display_error(error);
    repaint();
}

void Widget::on_ShiftButton_clicked()
{
    QString strX = ui->ShiftX->text();
    QString strY = ui->ShiftY->text();
    QString strZ = ui->ShiftZ->text();

    if (strX == NULL || strY == NULL || strZ == NULL)
    {
        display_error("Пустая строка!");
        return;
    }
    bool checkX, checkY, checkZ;
    double dx = strX.toDouble(&checkX);
    double dy = strY.toDouble(&checkY);
    double dz = strZ.toDouble(&checkZ);
    if (!checkX || !checkY || !checkZ)
    {
        display_error("Некорректный ввод!");
        return;
    }
    actionDataType data;

    data.param.shiftData.dx = dx;
    data.param.shiftData.dy = dy;
    data.param.shiftData.dz = dz;
    error_type error;
    if ((error = find_action(sshift, data)))
    {
        display_error(error);
        return;
    }
    lines.clear();

    if ((error = find_action(draw, data)))
        display_error(error);

    repaint();
}

void Widget::on_ScaleButton_clicked()
{
    QString str_kx = ui->ScaleX->text();
    QString str_ky = ui->ScaleY->text();
    QString str_kz = ui->ScaleZ->text();
    QString str_cx = ui->CenterX->text();
    QString str_cy = ui->CenterY->text();
    QString str_cz = ui->CenterZ->text();

    if (str_kx == NULL || str_ky == NULL || str_kz == NULL || \
            str_cx == NULL || str_cy == NULL || str_cz == NULL)
    {
        display_error("Пустые поля!");
        return;
    }
    bool checkKX, checkKY, checkKZ;
    bool checkCX, checkCY, checkCZ;
    double kx = str_kx.toDouble(&checkKX);
    double ky = str_ky.toDouble(&checkKY);
    double kz = str_kz.toDouble(&checkKZ);
    double cx = str_cx.toDouble(&checkCX);
    double cy = str_cy.toDouble(&checkCY);
    double cz = str_cz.toDouble(&checkCZ);

    if (!checkKX || !checkKY || !checkKZ || \
            !checkCX || !checkCY || !checkCZ)
    {
        display_error("Некорректные данные!");
        return;
    }
    actionDataType data;
    data.param.scaleData.kx = kx;
    data.param.scaleData.ky = ky;
    data.param.scaleData.kz = kz;
    data.param.scaleData.cx = cx;
    data.param.scaleData.cy = cy;
    data.param.scaleData.cz = cz;
    error_type error;
    if ((error = find_action(sscale, data)))
    {
        display_error(error);
        return;
    }
    lines.clear();
    if ((error = find_action(draw, data)))
        display_error(error);
    repaint();
}

void Widget::on_TurnButton_clicked()
{
    QString strX = ui->CenterX->text();
    QString strY = ui->CenterY->text();
    QString strZ = ui->CenterZ->text();
    QString strAngle = ui->TurnAngle->text();

    if (strX == NULL || strY == NULL || strZ == NULL || \
            strAngle == NULL)
    {
        display_error("Пустая строка!");
        return;
    }
    bool checkX, checkY, checkZ, checkAngle;
    double cx = strX.toDouble(&checkX);
    double cy = strY.toDouble(&checkY);
    double cz = strZ.toDouble(&checkZ);
    int angle = strAngle.toDouble(&checkAngle);
    if (!checkX || !checkY || !checkZ || !checkAngle)
    {
        display_error("Некорректный ввод!");
        return;
    }
    typeAxis axis;
    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;
    actionDataType data;

    data.param.turnData.cx = cx;
    data.param.turnData.cy = cy;
    data.param.turnData.cz = cz;
    data.param.turnData.angle = angle;
    data.param.turnData.axis = axis;

    error_type error;

    if ((error = find_action(turn, data)))
    {
        display_error(error);
        return;
    }

    lines.clear();

    if ((error = find_action(draw, data)))
        display_error(error);

    repaint();
}

void Widget::on_ProjectP_clicked()
{
    typeAxis axis;

    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;

    actionDataType data;

    data.param.projectPData.axis = axis;

    error_type error;

    if ((error = find_action(project_p, data)))
    {
        display_error(error);
        return;
    }

    lines.clear();

    if ((error = find_action(draw, data)))
        display_error(error);

    repaint();
}

void Widget::on_ProjectC_clicked()
{
    QString strDistance = ui->Distance->text();

    bool checkDistance;

    double distance = strDistance.toDouble(&checkDistance);

    if (!checkDistance)
    {
        display_error("Некорректный ввод!");
        return;
    }

    if (strDistance == NULL)
    {
        display_error("Некорректный ввод!");
        return;
    }

    typeAxis axis;

    if (ui->CheckX->isChecked())
        axis = X;
    else if (ui->CheckY->isChecked())
        axis = Y;
    else
        axis = Z;

    actionDataType data;

    data.param.projectCData.distance = distance;
    data.param.projectCData.axis = axis;

    error_type error;

    if ((error = find_action(project_c, data)))
    {
        display_error(error);
        return;
    }

    lines.clear();

    if ((error = find_action(draw, data)))
        display_error(error);

    repaint();
}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, \
    "lab_01", tr("Вы уверены?\n"), QMessageBox::No | QMessageBox::Yes, \
    QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
    {
        event->ignore();
    }
    else
    {
        error_type error;
        actionDataType data;

        if ((error = find_action(ffree, data)))
            display_error(error);

        event->accept();
    }

    error_type error;
    actionDataType data;

    if ((error = find_action(ffree, data)))
        display_error(error);
}

#endif // WIDGET_CPP
