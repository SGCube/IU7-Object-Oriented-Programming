#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QTimer>

#include "doors.h"

class Cabine : public QObject
{
	Q_OBJECT
public:
	explicit Cabine(QObject *parent = nullptr);
	~Cabine() {}

private:
	enum CabineState
	{
		STAND_BY,
		SET,
		START_MOVING,
		MOVING
	};
	
	enum Direction
	{
		UP,
		DOWN
	};
	Doors doors;
	
	CabineState state;
	Direction moveDirection;
	
	int currentFloor;
	int nextFloor;
	
	QTimer moveTimer;
    static const size_t moveInterval = 1500;
	
signals:
	void openDoors();
	void closeDoors();
	void floorReached();
	
	// message
	void sendMessage(const char* msg);
	void sendCurFloor(int floor);
	
private slots:
	void moving();							// MOVING
	void stop();							// STAND_BY

public slots:
	void setNextFloor(int floor);			// SET
	void startMoving();						// START_MOVING
	
	// messages
	void msgOpened() { emit sendMessage("Двери открыты"); }
	void msgOpening() { emit sendMessage("Двери открываются"); }
	void msgClosing() { emit sendMessage("Двери закрываются"); }
	void msgClosed() { emit sendMessage("Двери закрыты"); }

};

#endif
