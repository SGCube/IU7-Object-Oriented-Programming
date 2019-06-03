#include "doors.h"

Doors::Doors(QObject *parent) :
	QObject(parent),
	state(OPENED)
{
	openTimer.setInterval(openingTime);
	closeTimer.setInterval(closingTime);
	stayTimer.setInterval(stayTime);
	
	connect(&openTimer, SIGNAL(timeout()), this, SLOT(opened()));
	connect(&closeTimer, SIGNAL(timeout()), this, SLOT(closed()));
	connect(&stayTimer, SIGNAL(timeout()), this, SLOT(startClosing()));
	
	opened();
}

void Doors::startOpening()
{
	int leftTime = 0;
	if (state == CLOSING)
	{
		leftTime = closeTimer.remainingTime();
		closeTimer.stop();
	}
	
	state = OPENING;
	
	openTimer.start(openingTime - leftTime);
	
	emit doorsAreOpening();
}

void Doors::startClosing()
{
	state = CLOSING;
	
	stayTimer.stop();
	closeTimer.start();
	
	emit doorsAreClosing();
}

void Doors::opened()
{
	state = OPENED;
	
    openTimer.stop();
    stayTimer.start();
	
	emit doorsAreOpened();
}

void Doors::closed()
{
	state = CLOSED;
	
	closeTimer.stop();
	
	emit doorsAreClosed();
}
