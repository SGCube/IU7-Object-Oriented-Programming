#include "controller.h"

ElevatorController::ElevatorController(Cabine& cabine, Doors& doors,
									   QObject *parent) :
	QObject(parent),
	cabine(cabine),
	doors(doors),
	state(STAND_BY),
	currentFloor(1)
{
	connect(this, SIGNAL(doGoUp()), &cabine, SLOT(onGoUp()));
    connect(this, SIGNAL(doGoDown()), &cabine, SLOT(onGoDown()));
    connect(this, SIGNAL(doStop()), &cabine, SLOT(onStop()));
    connect(this, SIGNAL(doOpen()), &doors, SLOT(onOpening()));
	connect(this, SIGNAL(doClose()), &doors, SLOT(onClosing()));

    connect(&cabine, SIGNAL(doGoUp()), this, SLOT(onGoingUp()));
    connect(&cabine, SIGNAL(doGoDown()), this, SLOT(onGoingDown()));
    connect(&cabine, SIGNAL(doStop()), this, SLOT(onStop()));

    connect(&doors, SIGNAL(doOpening()), this, SLOT(onOpening()));
    connect(&doors, SIGNAL(doOpened()), this, SLOT(onOpened()));
    connect(&doors, SIGNAL(doClosing()), this, SLOT(onClosing()));
	connect(&doors, SIGNAL(doClosed()), this, SLOT(onClosed()));
	
	emit doMsgShow("Двери открыты");
	emit doFloorShow(1);
}

void ElevatorController::onPushButton(int floor)
{
    requestedFloors.insert(floor);
    if (state == STAND_BY)
	{
		if (doors.isOpened())
			emit doClose();
		else
			startMoving();
	}
	state = BUTTON_PUSHED;
}

void ElevatorController::onOpenButton()
{
	if (state == STAND_BY && !doors.isOpened())
		emit doOpen();
}

void ElevatorController::onCloseButton()
{
	if (state == STAND_BY && doors.isOpened())
		emit doClose();
}

void ElevatorController::onGoingUp()
{
    ++currentFloor;
	emit doFloorShow(currentFloor);
    if (requestedFloors.find(currentFloor) != requestedFloors.end())
	{
        emit doStop();
		emit doOpen();
	}
    state = GO_UP;
}

void ElevatorController::onGoingDown()
{
    --currentFloor;
    emit doFloorShow(currentFloor);
    if (requestedFloors.find(currentFloor) != requestedFloors.end())
	{
        emit doStop();
		emit doOpen();
	}
	state = GO_DOWN;
}

void ElevatorController::onStop()
{
	state = STAND_BY;
}

void ElevatorController::onOpening()
{
    emit doMsgShow("Двери открываются");
}

void ElevatorController::onOpened()
{
    emit doMsgShow("Двери открыты");
    requestedFloors.erase(currentFloor);
    state = STAND_BY;
}

void ElevatorController::onClosing()
{
    emit doMsgShow("Двери закрываются");
}

void ElevatorController::onClosed()
{
    emit doMsgShow("Двери закрыты");
	state = STAND_BY;
	startMoving();
}

int ElevatorController::getNearestLevel()
{
    int nearest = 0;
    for (auto floor = requestedFloors.begin(); floor != requestedFloors.end();
		 floor++)
	{
        if ((nearest == 0) || (abs(currentFloor - (*floor)) < abs(currentFloor - nearest)))
		{
            nearest = *floor;
        }
    }
	return nearest;
}

void ElevatorController::startMoving()
{
	int nearest = getNearestLevel();
	if (nearest != 0)
	{
        if (nearest > currentFloor)
            emit doGoUp();
		else if (nearest < currentFloor)
            emit doGoDown();
        else
            emit doOpen();
    }
}
