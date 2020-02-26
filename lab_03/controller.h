#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>

#include "cabine.h"
#include "direction.h"

class ElevatorController : public QObject
{
	Q_OBJECT
	
public:
	explicit ElevatorController(Cabine& cabine, int floors,
								QObject *parent = nullptr);
	~ElevatorController() {}
	
private:
	enum ControllerState
	{
		STAND_BY,
		IN_PROCESS
	};
	
	Cabine& cabine;
	ControllerState state;
	Direction curDirection;
	
	int currentFloor;
	int nextFloor;
	int floorsAmount;
	
	std::vector<bool> requestedFloors;
	
	bool defineNextFloor();
	bool defineNearestFloor();
	
signals:
	void setFloorToReach(int floor);	// to Cabine
	void requestSatisfied(int floor);	// to Window/Button
	
	// messages
	void showCurFloor(int floor);
	void showMessage(const char* msg);
	
public slots:
	// state
    void requestFloor(int floor);
	void floorReached();
	
	// data
	void getCurFloor(int floor);
	void getDirection(Direction dir) { curDirection = dir; }
	
	// messages
	void getMessage(const char* msg) { emit showMessage(msg); }
};

#endif // CONTROLLER_H
