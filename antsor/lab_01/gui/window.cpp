#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "window.h"
#include "../ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

#endif // WINDOW_CPP
