#include "doors.h"

Doors::Doors(QObject *parent) :
	QObject(parent),
	state(OPENED)
{
}

void Doors::open()
{
	if (state == CLOSED || state == CLOSING)
		state = OPENING;
}

void Doors::close()
{
	if (state == OPENED || state == OPENING)
		state = CLOSING;
}

bool Doors::isOpened()
{
	return state == OPENED;
}

void Doors::onOpening()
{
	emit doOpening();
    timer = new QTimer;
    timer->setInterval(openingTime);
    connect(timer, SIGNAL(timeout()), this, SLOT(onOpened()));
    timer->start();
    state = OPENING;
}

void Doors::onOpened()
{
	emit doOpened();
    timer = new QTimer;
    timer->setInterval(standTime);
    connect(timer, SIGNAL(timeout()), this, SLOT(onClosing()));
    timer->start();
    state = OPENING;
}

void Doors::onClosing()
{
	emit doClosing();
    timer = new QTimer;
    timer->setInterval(closingTime);
    connect(timer, SIGNAL(timeout()), this, SLOT(onClosed()));
    timer->start();
    state = OPENING;
}

void Doors::onClosed()
{
	delete timer;
    emit doClosed();
    state = CLOSED;
}
