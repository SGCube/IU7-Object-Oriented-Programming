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
	connect(this, SIGNAL(setNextFloor(int)), &cabine, SLOT(setNextFloor(int)));
	connect(&cabine, SIGNAL(floorReached()), this, SLOT(floorReached()));
	
	// messages
	connect(&cabine, SIGNAL(sendMessage(const char*)),
			this, SLOT(getMessage(const char*)));
	connect(&cabine, SIGNAL(sendCurFloor(int)), this, SLOT(getCurFloor(int)));
	
	
	for (int i = 0; i <= floorsAmount; i++)
		requestedFloors.push_back(false);
	
	emit showMessage("Двери открыты");
	emit showCurFloor(1);
}

void ElevatorController::defineNextFloor()
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
		state = STAND_BY;
	}
	else
		emit setNextFloor(nextFloor);
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

void ElevatorController::onPushButton(int floor)
{
	if (floor != currentFloor)
	{
		requestedFloors[floor] = true;
		if (state == STAND_BY)
		{
			state = IN_PROCESS;
			defineNextFloor();
		}
	}
	else
		emit pullButton(floor);
}

void ElevatorController::floorReached()
{
	state = STAND_BY;
	prevFloor = currentFloor;
	currentFloor = nextFloor;
	requestedFloors[currentFloor] = false;
	
	emit pullButton(currentFloor);
	
	defineNextFloor();
}
