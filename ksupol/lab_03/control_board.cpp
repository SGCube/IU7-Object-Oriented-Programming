#include "control_board.h"

Control_board::Control_board(QObject *parent) : QObject(parent)
{
    current_state = FREE;
    current_direction = STOP;
    current_floor = 0;
    for (int i = 0; i < FLOORS_NUMBERS; i++)
        targets[i] = false;
}

void Control_board::set_new_target(int floor)
{
    current_state = BUSY;
    targets[floor - 1] = true;
    next_target(floor);
    emit set_target(floor);
}

void Control_board::set_text(QTextEdit *t)
{
    text = t;
    text->append("Панель управления подключена");
}

void Control_board::achieved_floor(int floor)
{
    if (current_state == BUSY)
    {
        current_floor = floor;
        current_direction = STOP;
        targets[floor - 1] = false;
        if (next_target(floor))
            emit set_target(floor);
        else
            current_state = FREE;
    }
}

void Control_board::passed_floor(int floor, direction d)
{
    current_floor = floor;
    current_direction = d;
    QString act = (d == UP ? "поднимается ":"опускается ");
    int f1 = floor;
    int f2;
    if (d == UP)
        f2 = floor++;
    else
        f2 = floor--;
    text->append("Лифт " + act + "между этажами " + QString::number(f1) + " и " + QString::number(f2));

}

bool Control_board::next_target(int &floor)
{
    int step = -1;
    if (current_direction == UP)
        step = 1;
    for (int i = current_floor; i <= FLOORS_NUMBERS && i > 0; i += step)
    {
        if (targets[i - 1])
        {
            floor = i;
            return true;
        }
    }
    step = -step;
    for (int i = current_floor; i <= FLOORS_NUMBERS && i > 0; i+= step)
    {
        if (targets[i - 1])
        {
            floor = i;
            return true;
        }
    }
    return false;
}
