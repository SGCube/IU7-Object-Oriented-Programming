#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <set>

#include "cabine.h"
#include "doors.h"

class ElevatorController : public QObject
{
	Q_OBJECT
	
public:
	ElevatorController(Cabine& cabine, Doors& doors, QObject *parent = nullptr);
	~ElevatorController() {}
	
private:
	enum State
	{
		BUTTON_PUSHED,
		GO_UP,
		GO_DOWN,
		STAND_BY
	};
	
	Cabine& cabine;
	Doors& doors;
	
	State state;
	int currentFloor;
	std::set<int> requestedFloors;
	
	int getNearestLevel();
	void startMoving();
	
signals:
    void doGoUp();
    void doGoDown();
    void doOpen();
    void doClose();
    void doStop();
	void doFloorShow(int floor);
	void doMsgShow(const char* msg);
	
public slots:
    void onPushButton(int floor);
	void onOpenButton();
	void onCloseButton();
	
	void onGoingUp();
    void onGoingDown();
	void onStop();
    void onOpening();
    void onClosing();
	void onOpened();
	void onClosed();
};

#endif // CONTROLLER_H
