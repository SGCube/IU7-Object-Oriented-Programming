#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setUpCanvas();
    ui->modelBox->addItem("Все модели");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setUpCanvas()
{
    this->canvas = new QGraphicsScene;
    ui->Canvas->installEventFilter(this);
    ui->Canvas->setScene(canvas);
    ui->addButton->click();
}

void Widget::updateCanvas()
{
    this->canvas->clear();
    ModelDrawer drawer(this->canvas);

    size_t index = ui->cameraBox->currentIndex();
    actions::ModelDrawAction action(drawer, index);
    actionController.executeAction(action);
}

void Widget::on_addButton_clicked()
{
    try
    {
        actions::CameraAddAction action(0, 0, 0);
        actionController.executeAction(action);

        ui->cameraBox->addItem("Камера " + QString::number(ui->cameraBox->count()));
        ui->cameraBox->setCurrentIndex(ui->cameraBox->count() - 1);
    }
    catch (ExceptionBase& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_deleteButton_clicked()
{
    try
    {
        if (ui->cameraBox->count() == 1)
            return;

        actions::CameraRemoveAction action(ui->cameraBox->currentIndex());
        actionController.executeAction(action);

        ui->cameraBox->removeItem(ui->cameraBox->currentIndex());
        ui->cameraBox->setCurrentIndex(0);
    }
    catch (ExceptionBase& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_loadButton_clicked()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Загрузить", "",
                                                        "Текстовый файл (*.txt)");
        if (filePath.isEmpty())
        {
            QMessageBox::warning(this, "Error", "No file choosen");
            return;
        }

        actions::ModelUploadAction action(filePath.toStdString());
        actionController.executeAction(action);

        ui->modelBox->addItem("Модель " + QString::number(ui->modelBox->count()));
        ui->modelBox->setCurrentIndex(ui->modelBox->count() - 1);

        this->updateCanvas();
    }
    catch (ExceptionBase& e)
    {
        QMessageBox::warning(this, "Error", QString(e.what()));
    }
}

void Widget::on_cameraBox_currentIndexChanged(int index)
{
	Q_UNUSED(index);
    this->updateCanvas();
}

void Widget::on_moveButton_clicked()
{
	size_t index = ui->modelBox->currentIndex() - 1;
	actions::ModelMoveAction action(ui->dxBox->value(), 
									 ui->dyBox->value(), 
									 ui->dzBox->value(), index);
	actionController.executeAction(action);
	this->updateCanvas();
}

void Widget::on_scaleButton_clicked()
{
	size_t index = ui->modelBox->currentIndex() - 1;
	actions::ModelScaleAction action(ui->kxBox->value(), 
									 ui->kyBox->value(),
									 ui->kzBox->value(),
									 index);
	actionController.executeAction(action);
	this->updateCanvas();
}

void Widget::on_rotateButton_clicked()
{
	size_t index = ui->modelBox->currentIndex() - 1;
	actions::ModelRotateAction action(ui->axBox->value(), 
									  ui->ayBox->value(),
									  ui->azBox->value(),
									  index);
	actionController.executeAction(action);
	this->updateCanvas();
}

void Widget::on_rotateCButton_clicked()
{
	size_t index = ui->cameraBox->currentIndex();
	actions::CameraRotateAction action(ui->axBox->value(), 
									  ui->ayBox->value(),
									  ui->azBox->value(),
									  index);
	actionController.executeAction(action);
	this->updateCanvas();
}
