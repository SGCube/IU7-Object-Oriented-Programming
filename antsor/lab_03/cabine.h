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
	~Cabine();

private:
	enum CabineState
	{
		MOVING,
		START_MOVING,
		STAND_BY,
		SET,
		CLOSED_STAND_BY
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
	
	QTimer* timer;
    static const size_t moveInterval = 1500;
	
	void startMoving();
	
signals:
	void open();
	
	void sendMessage(const char* msg);
	void sendCurFloor(int floor);
	void floorReached();
	
private slots:
	void moving();							// MOVING

public slots:
	void setNextFloor(int floor);			// SET
	void doorsClosed();						// START_MOVING / IDLE
	void stop();							// STAND_BY
	
	// messages
	void msgOpened() { emit sendMessage("Двери открыты"); }
	void msgOpening() { emit sendMessage("Двери открываются"); }
	void msgClosing() { emit sendMessage("Двери закрываются"); }
	void msgClosed() { emit sendMessage("Двери закрыты"); }
};

#endif
