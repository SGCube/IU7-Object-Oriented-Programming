#include "controller.h"

ElevatorController::ElevatorController(Cabine& cabine, int floors,
									   QObject *parent) :
	QObject(parent),
	cabine(cabine),
	state(STAND_BY),
	curDirection(STAND),
	currentFloor(1),
	nextFloor(1),
	floorsAmount(floors)
{
	for (int i = 0; i <= floorsAmount; i++)
		requestedFloors.push_back(false);
	
	connect(this, SIGNAL(setFloorToReach(int)), &cabine, SLOT(setNextFloor(int)));
	connect(&cabine, SIGNAL(stopped()), this, SLOT(floorReached()));
	
	// data
	connect(&cabine, SIGNAL(sendCurFloor(int)), this, SLOT(getCurFloor(int)));
	connect(&cabine, SIGNAL(sendCurDir(Direction)), this, SLOT(getDirection(Direction)));
	
	// messages
	connect(&cabine, SIGNAL(sendMessage(const char*)),
			this, SLOT(getMessage(const char*)));
}

bool ElevatorController::defineNextFloor()
{
	if (curDirection == STAND)
		return defineNearestFloor();
	
	int step = 1;
	if (curDirection == DOWN)
		step = -1;
	
	for (int i = currentFloor; 0 < i && i <= floorsAmount; i += step)
	{
		if (requestedFloors[i])
		{
			nextFloor = i;
			return true;
		}
	}
	
	step = -step;
	for (int i = currentFloor; 0 < i && i <= floorsAmount; i+= step)
	{
		if (requestedFloors[i])
		{
			nextFloor = i;
			return true;
		}
	}
	
	return false;
}

bool ElevatorController::defineNearestFloor()
{
	bool lower = false, higher = false;
	int nextLower = currentFloor, nextHigher = currentFloor;
	
	for (int i = currentFloor; 0 < i && !lower; i--)
	{
		if (requestedFloors[i])
		{
			nextLower = i;
			lower = true;
		}
	}
	
	for (int i = currentFloor; i <= floorsAmount && !higher; i++)
	{
		if (requestedFloors[i])
		{
			nextHigher = i;
			higher = true;
		}
	}
	
	if (!(lower || higher))
		return false;
	
	if (lower && higher)
	{
		int distLower = currentFloor - nextLower;
		int distHigher = nextHigher - currentFloor;
		nextFloor = (distLower < distHigher) ? nextLower : nextHigher;
	}
	else if (lower)
		nextFloor = nextLower;
	else
		nextFloor = nextHigher;
		
	return true;
}

void ElevatorController::requestFloor(int floor)
{
	state = IN_PROCESS;
	
	requestedFloors[floor] = true;
	defineNextFloor();
	emit setFloorToReach(nextFloor);
}

void ElevatorController::floorReached()
{
	if (state == IN_PROCESS)
	{
		currentFloor = nextFloor;
		requestedFloors[currentFloor] = false;
		emit requestSatisfied(currentFloor);
		
		if (defineNextFloor())
			emit setFloorToReach(nextFloor);
		else
		{
			state = STAND_BY;
			curDirection = STAND;
		}
	}
}

void ElevatorController::getCurFloor(int floor)
{
	currentFloor = floor;
	emit showCurFloor(floor);
}
