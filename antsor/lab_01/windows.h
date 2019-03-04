#ifndef WINDOWS_H
#define WINDOWS_H

#include <QMainWindow>

namespace Ui {
class windows;
}

class windows : public QMainWindow
{
    Q_OBJECT

public:
    explicit windows(QWidget *parent = 0);
    ~windows();

private:
    Ui::windows *ui;
};

#endif // WINDOWS_H
