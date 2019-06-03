#include "lift.h"

Lift::Lift()
{
    QObject::connect(&cp, SIGNAL(set_target(int)), &cab, SLOT(cabin_set_target(int)));
    QObject::connect(&cab, SIGNAL(passing_floor(int,direction)), &cp, SLOT(passed_floor(int,direction)));
    QObject::connect(&cab, SIGNAL(cabin_stopped(int)), &cp, SLOT(achieved_floor(int)));
}

void Lift::set_action_text(QTextEdit *t)
{
    this->action_text = t;
    action_text->append("Лифт:");
    cab.set_text(action_text);
    cp.set_text(action_text);
}

void Lift::add_stop(int floor)
{
    cp.set_new_target(floor);
}

