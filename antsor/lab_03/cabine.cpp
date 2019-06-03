#include "cabine.h"

Cabine::Cabine(QObject *parent) :
	QObject(parent),
	doors(),
	state(STAND_BY),
	moveDirection(UP),
	currentFloor(1),
	nextFloor(1)
{
	connect(this, SIGNAL(openDoors()), &doors, SLOT(startOpening()));
	connect(this, SIGNAL(closeDoors()), &doors, SLOT(startClosing()));
	connect(&doors, SIGNAL(doorsAreClosed()), this, SLOT(startMoving()));
	
	connect(&moveTimer, SIGNAL(timeout()), this, SLOT(moving()));
	
	// messages
	connect(&doors, SIGNAL(doorsAreOpened()), this, SLOT(msgOpened()));
	connect(&doors, SIGNAL(doorsAreOpening()), this, SLOT(msgOpening()));
	connect(&doors, SIGNAL(doorsAreClosed()), this, SLOT(msgClosed()));
	connect(&doors, SIGNAL(doorsAreClosing()), this, SLOT(msgClosing()));
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

void Cabine::stop()
{
	state = STAND_BY;
	
	moveTimer.stop();
	emit floorReached();
	emit openDoors();
}

void Cabine::setNextFloor(int floor)
{
	state = SET;
	
	nextFloor = floor;
	if (nextFloor == floor)
	{
		emit floorReached();
		emit openDoors();
	}
	else
	{
		moveDirection = (nextFloor > currentFloor) ? UP : DOWN;
		emit closeDoors();
	}
}

void Cabine::startMoving()
{
	state = START_MOVING;
	
	if (nextFloor < currentFloor)
		moveDirection = DOWN;
	else if (nextFloor > currentFloor)
		moveDirection = UP;
	
	moveTimer.start();
}
