#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>

#include "cabine.h"

class ElevatorController : public QObject
{
	Q_OBJECT
	
public:
	ElevatorController(Cabine& cabine, int floors, QObject *parent = nullptr);
	~ElevatorController() {}
	
private:
	enum ControllerState
	{
		STAND_BY,
		IN_PROCESS
	};
	
	Cabine& cabine;
	ControllerState state;
	
	int prevFloor;
	int currentFloor;
	int nextFloor;
	int floorsAmount;
	
	std::vector<bool> requestedFloors;
	
	void defineNextFloor();
	int getNearestFloor();
	int getHigherFloor();
	int getLowerFloor();
	
signals:
	void setNextFloor(int floor);
	void pullButton(int floor);
	
	// messages
	void showCurFloor(int floor);
	void showMessage(const char* msg);
	
public slots:
    void onPushButton(int floor);
	void floorReached();
	
	// messages
	void getMessage(const char* msg) { emit showMessage(msg); }
	void getCurFloor(int floor) { emit showCurFloor(floor); }
};

#endif // CONTROLLER_H
