#include "doors.h"

Doors::Doors(QObject *parent) :
	QObject(parent),
	state(OPENED)
{
	openTimer.setInterval(openingTime);
	closeTimer.setInterval(closingTime);
	stayTimer.setInterval(stayTime);
	
	openTimer.setSingleShot(true);
	closeTimer.setSingleShot(true);
	stayTimer.setSingleShot(true);
	
	
	connect(&openTimer, SIGNAL(timeout()), this, SLOT(opened()));
	connect(&closeTimer, SIGNAL(timeout()), this, SLOT(closed()));
	connect(&stayTimer, SIGNAL(timeout()), this, SLOT(startClosing()));
	
	opened();
}

void Doors::startOpening()
{
	if (state == CLOSED || state == CLOSING)
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
	else if (state == OPENED)
		emit doorsAreOpened();
}

void Doors::startClosing()
{
	if (state == OPENED)
	{
		state = CLOSING;
		closeTimer.start();
		emit doorsAreClosing();
	}
	else if (state == CLOSED)
		emit doorsAreClosed();
}

void Doors::opened()
{
	state = OPENED;
    stayTimer.start();
	emit doorsAreOpened();
}

void Doors::closed()
{
	state = CLOSED;
	emit doorsAreClosed();
}
