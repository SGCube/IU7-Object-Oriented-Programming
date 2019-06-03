#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include "cabine.h"
#include "control_board.h"

class Lift : public QObject
{
    Q_OBJECT
public:
    Lift();
    void set_action_text(QTextEdit *t);
    void add_stop(int floor);

signals:

public slots:

private:
    QTextEdit *action_text;
    Control_board cp;
    Cabine cab;
};

#endif // LIFT_H
