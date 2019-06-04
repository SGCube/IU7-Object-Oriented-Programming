#include "cabine.h"

Cabine::Cabine(QObject *parent) : QObject(parent)
{
    current_direction = STOP;
    current_floor = 1;
    current_state = WAIT;
    moving_one_floor_timer.setSingleShot(true);
    QObject::connect(this, SIGNAL(reached_target_floor(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
    QObject::connect(&doors, SIGNAL(closeddoors()), this, SLOT(cabin_moving()));
    QObject::connect(&moving_one_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_moving()));
    QObject::connect(this, SIGNAL(go()), &doors, SLOT(start_closing()));
}

void Cabine::set_text(QTextEdit *t)
{
    text = t;
    text->append("Кабина работает");
    doors.set_text(t);
}

void Cabine::cabin_moving()
{
    if (current_state == GOT_AIM)
    {
        if (current_floor == target_floor)
            emit reached_target_floor(current_floor);
        else
        {
            current_state = MOVING;
            moving_one_floor_timer.start(MOVING_ONE_FLOOR_TIME);
        }
    }
    if (current_state == MOVING)
    {
        if (current_direction == UP)
            current_floor++;
        else
            current_floor--;
        if (current_floor == target_floor)
            emit reached_target_floor(current_floor);
        else
        {
            emit passing_floor(current_floor, current_direction);
            moving_one_floor_timer.start(MOVING_ONE_FLOOR_TIME);
        }
    }
}

void Cabine::cabin_stopping()
{
    current_state = WAIT;
    moving_one_floor_timer.stop();
    text->append("Лифт остановился на этаже " + QString::number(current_floor));
    emit cabin_stopped(current_floor);
}

void Cabine::cabin_set_target(int floor)
{
    current_state = GOT_AIM;
    target_floor = floor;
    if (current_floor == target_floor)
        emit reached_target_floor(floor);
    else
    {
        current_direction = (current_floor > target_floor) ? DOWN : UP;
        emit go();
    }
}
