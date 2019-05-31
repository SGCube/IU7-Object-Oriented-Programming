#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QTimer>

class Cabine : public QObject
{
	Q_OBJECT
public:
	explicit Cabine(QObject *parent = nullptr);
	~Cabine() {}

private:
	enum CabineState
	{
		GO_UP,
		GO_DOWN,
		STAND_BY
	};
	
	CabineState state;
	int currentFloor;
	
	QTimer* timer;
    static const size_t moveInterval = 2000;
	
signals:
    void doGoUp();
    void doGoDown();
    void doStop();

public slots:
    void onGoUp();
    void onGoDown();
    void onStop();
    void GoUpEmitter() {emit doGoUp();}
    void GoDownEmitter() {emit doGoDown();}
};

#endif
