#include "cabine.h"

Cabine::Cabine(QObject *parent) :
	QObject(parent),
	doors(),
	state(STAND_BY),
	moveDirection(UP),
	currentFloor(1),
	nextFloor(1),
	timer(nullptr)
{
	connect(this, SIGNAL(open()), &doors, SLOT(open()));
	connect(&doors, SIGNAL(sendClosed()), this, SLOT(startMoving()));
	
	// messages
	connect(&doors, SIGNAL(msgClosing()), this, SLOT(msgClosing()));
	connect(&doors, SIGNAL(msgOpened()), this, SLOT(msgOpened()));
	connect(&doors, SIGNAL(msgOpening()), this, SLOT(msgOpening()));
	
	timer = new QTimer;
}

Cabine::~Cabine()
{
	delete timer;
}

void Cabine::startMoving()
{
	state = START_MOVING;
	
	if (nextFloor < currentFloor)
		moveDirection = DOWN;
	else if (nextFloor > currentFloor)
		moveDirection = UP;
	
	timer->setInterval(moveInterval);
	connect(timer, SIGNAL(timeout()), this, SLOT(moving()));
	timer->start();
}

void Cabine::moving()
{
	state = MOVING;
	
	if (moveDirection == UP)
		currentFloor++;
	else if (moveDirection == DOWN)
		currentFloor--;
	
	if (currentFloor == nextFloor)
        stop();
	
	emit sendCurFloor(currentFloor);
}

void Cabine::setNextFloor(int floor)
{
	if (state == STAND_BY)
	{
		state = SET;
		nextFloor = floor;
	}
	else if (state == CLOSED_STAND_BY)
	{
		emit open();
		emit sendMessage("Двери открываются");
	}
	else
	{
		if (floor < nextFloor && moveDirection == UP)
			nextFloor = floor;
		else if (floor > nextFloor && moveDirection == DOWN)
			nextFloor = floor;
	}
}

void Cabine::stop()
{
	state = STAND_BY;
	timer->stop();
	
	emit open();
	emit sendMessage("Двери открываются");
	emit floorReached();
}

void Cabine::doorsClosed()
{
	emit sendMessage("Двери закрыты");
	if (state == SET)
		startMoving();
}
