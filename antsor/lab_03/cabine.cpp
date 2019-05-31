#include "cabine.h"

Cabine::Cabine(QObject *parent) :
	QObject(parent),
	state(STAND_BY),
	currentFloor(1)
{
}

void Cabine::onGoUp()
{
    timer = new QTimer;
    timer->setInterval(moveInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(GoUpEmitter()));
    timer->start();
    state = GO_UP;
}

void Cabine::onGoDown()
{
	timer = new QTimer;
    timer->setInterval(moveInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(GoDownEmitter()));
    timer->start();
    state = GO_DOWN;
}

void Cabine::onStop()
{
	delete timer;
    emit doStop();
    state = STAND_BY;
}
