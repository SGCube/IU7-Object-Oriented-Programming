#include "doors.h"

Doors::Doors(QObject *parent) :
	QObject(parent),
	state(OPENED),
	timer(nullptr)
{
	timer = new QTimer;
	opened();
}

Doors::~Doors()
{
	delete timer;
}

void Doors::startClosing()
{
	state = CLOSING;
	emit msgClosing();
	
	timer->stop();
	timer->setInterval(closingTime);
	connect(timer, SIGNAL(timeout()), this, SLOT(closed()));
	timer->start();
}

void Doors::closed()
{
	state = CLOSED;
	timer->stop();
	emit sendClosed();
}

void Doors::startOpening()
{
	state = OPENING;
	emit msgOpening();
	
	int left = timer->remainingTime();
	timer->stop();
	timer->setInterval(openingTime - left);
	connect(timer, SIGNAL(timeout()), this, SLOT(opened()));
	timer->start();
}

void Doors::opened()
{
	state = OPENED;
	emit msgOpened();
	
    timer->stop();
    timer->setInterval(standTime);
    connect(timer, SIGNAL(timeout()), this, SLOT(startClosing()));
    timer->start();
}
