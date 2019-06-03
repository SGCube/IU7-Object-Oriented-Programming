#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QString>
#include "diraction.h"
#include "doors.h"

class Cabine : public QObject
{
    Q_OBJECT
    enum cabin_state
    {
        WAIT,
        GOT_AIM,
        MOVING
    };

public:
    explicit Cabine(QObject *parent = nullptr);
    void set_text(QTextEdit *t);

signals:
    void go();
    void passing_floor(int floor, direction d);
    void reached_target_floor(int floor);
    void cabin_stopped(int floor);

public slots:
    void cabin_moving();
    void cabin_stopping();
    void cabin_set_target(int floor);


private:
    int current_floor;
    int target_floor;
    cabin_state current_state;
    direction current_direction;
    Doors doors;
    QTimer moving_one_floor_timer;

    QTextEdit *text;
};

#endif // CABINE_H
