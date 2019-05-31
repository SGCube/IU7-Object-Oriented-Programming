#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT
public:
	Doors(QObject *parent = nullptr);
	~Doors() {}

	void open();
	void close();
	bool isOpened();

private:
	enum DoorsState
	{
		OPENING,
		OPENED,
		CLOSING,
		CLOSED
	};

	DoorsState state;
	QTimer* timer;
	
    static const size_t openingTime = 1000;
    static const size_t closingTime = 1000;
    static const size_t standTime = 2000;
	
signals:
    void doOpening();
    void doOpened();
    void doClosing();
    void doClosed();

public slots:
    void onOpening();
    void onOpened();
    void onClosing();
    void onClosed();	

};

#endif
