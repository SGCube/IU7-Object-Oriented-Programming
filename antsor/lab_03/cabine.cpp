#include "cabine.h"

Cabine::Cabine(QObject *parent) :
	QObject(parent),
	doors(),
	state(STAND_BY),
	moveDirection(UP),
	currentFloor(1),
	nextFloor(1)
{
	moveTimer.setInterval(moveInterval);
	
	connect(this, SIGNAL(openDoors()), &doors, SLOT(startOpening()));
	connect(this, SIGNAL(closeDoors()), &doors, SLOT(startClosing()));
	connect(&doors, SIGNAL(doorsAreClosed()), this, SLOT(startMoving()));
	
	connect(&moveTimer, SIGNAL(timeout()), this, SLOT(moving()));
	
	// messages
	connect(&doors, SIGNAL(doorsAreOpened()), this, SLOT(msgOpened()));
	connect(&doors, SIGNAL(doorsAreOpening()), this, SLOT(msgOpening()));
	connect(&doors, SIGNAL(doorsAreClosed()), this, SLOT(msgClosed()));
	connect(&doors, SIGNAL(doorsAreClosing()), this, SLOT(msgClosing()));
	
	emit sendCurFloor(currentFloor);
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
	emit openDoors();
	emit stopped();
}

void Cabine::setNextFloor(int floor)
{
	nextFloor = floor;
	if (nextFloor == currentFloor)
		stop();
	else if (state == STAND_BY)
	{
		state = SET;
		moveDirection = (nextFloor > currentFloor) ? UP : DOWN;
		emit closeDoors();
	}
}

void Cabine::startMoving()
{
	if (state == SET)
	{
		state = START_MOVING;
		
		if (nextFloor < currentFloor)
			moveDirection = DOWN;
		else if (nextFloor > currentFloor)
			moveDirection = UP;
		
		moveTimer.start();
		emit sendCurDir(moveDirection);
	}
}
