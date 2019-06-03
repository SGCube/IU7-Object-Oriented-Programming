#include "controller.h"

ElevatorController::ElevatorController(Cabine& cabine, int floors,
									   QObject *parent) :
	QObject(parent),
	cabine(cabine),
	state(STAND_BY),
	prevFloor(0),
	currentFloor(1),
	nextFloor(1),
	floorsAmount(floors)
{
	for (int i = 0; i <= floorsAmount; i++)
		requestedFloors.push_back(false);
	
	connect(this, SIGNAL(setFloorToReach(int)), &cabine, SLOT(setNextFloor(int)));
	connect(&cabine, SIGNAL(stopped()), this, SLOT(floorReached()));
	
	// messages
	connect(&cabine, SIGNAL(sendMessage(const char*)),
			this, SLOT(getMessage(const char*)));
	connect(&cabine, SIGNAL(sendCurFloor(int)), this, SLOT(getCurFloor(int)));
}

bool ElevatorController::defineNextFloor()
{
	if (prevFloor < currentFloor)
		nextFloor = getHigherFloor();
	else if (prevFloor > currentFloor)
		nextFloor = getLowerFloor();
	else
		nextFloor = getNearestFloor();
	
	if (nextFloor == floorsAmount + 1)
		nextFloor = getLowerFloor();
	if (nextFloor == 0)
		nextFloor = getHigherFloor();
	
	if (nextFloor == 0 || nextFloor == floorsAmount + 1)
	{
		nextFloor = currentFloor;
		return false;
	}
	return true;
}

int ElevatorController::getNearestFloor()
{
	int nearestHigher = getHigherFloor();
	int nearestLower = getLowerFloor();
	
	if (nearestHigher == floorsAmount + 1)
		return nearestLower;
	if (nearestLower == 0)
		return nearestHigher;
	
	int distLower = currentFloor - nearestLower;
	int distHigher = nearestHigher - currentFloor;
	
	return (distLower < distHigher) ? nearestLower : nearestHigher;
}

int ElevatorController::getHigherFloor()
{
	int i = currentFloor + 1;
	while (i <= floorsAmount && !requestedFloors[i])
		i++;
	return i;
}

int ElevatorController::getLowerFloor()
{
	int i = currentFloor - 1;
		while (i > 0 && !requestedFloors[i])
			i--;
	return i;
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
		prevFloor = currentFloor;
		currentFloor = nextFloor;
		
		requestedFloors[currentFloor] = false;
		emit requestSatisfied(currentFloor);
		
		if (defineNextFloor())
			emit setFloorToReach(nextFloor);
		else
			state = STAND_BY;
	}
}
