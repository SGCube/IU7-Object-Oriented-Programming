#include "doors.h"

Doors::Doors(QObject *parent) : QObject(parent)
{
    current_state = OPENED;
    doors_stay_open_timer.setInterval(DOORS_OPEN_TIME);
    doors_stay_open_timer.setSingleShot(true);
    doors_open_timer.setSingleShot(true);
    doors_close_timer.setSingleShot(true);
    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(openeddoors()), &doors_stay_open_timer, SLOT(start()));
    QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this, SLOT(start_closing()));
}

void Doors::set_text(QTextEdit *t)
{
    text = t;
    text->append("Двери открыты");
}

void Doors::start_openning()
{
    if (current_state == CLOSED)
    {
        current_state = OPENNING;
        text->append("Двери открываются");
        doors_open_timer.start(DOORS_CLOSE_OPEN);
    }
    if (current_state == CLOSING)
    {
        current_state = OPENNING;
        text->append("Двери открываются");
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(DOORS_CLOSE_OPEN - t);
    }
}

void Doors::start_closing()
{
    if (current_state == OPENED)
    {
        current_state = CLOSING;
        text->append("Двери закрываются");
        doors_close_timer.start(DOORS_CLOSE_OPEN);
    }
    else if (current_state == CLOSED)
        emit closeddoors();
}

void Doors::open()
{
    if (current_state == OPENNING)
    {
        current_state = OPENED;
        text->append("Двери открыты");
        emit openeddoors();
    }
}

void Doors::close()
{
    if (current_state == CLOSING)
    {
        current_state = CLOSED;
        text->append("Двери закрыты");
        emit closeddoors();
    }
}
