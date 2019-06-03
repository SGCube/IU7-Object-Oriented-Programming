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

private:
	enum DoorsState
	{
		OPENED,
		CLOSING,
		CLOSED,
		OPENING
	};

	DoorsState state;
	
	QTimer openTimer;
	QTimer closeTimer;
	QTimer stayTimer;
	
    static const size_t openingTime = 1000;
    static const size_t closingTime = 1000;
    static const size_t stayTime = 5000;
	
signals:
    void doorsAreClosed();
	
	// messages
	void msgOpened();
	void msgClosing();
	void msgOpening();

public slots:
	void startOpening();
    void startClosing();
	
private slots:
	void opened();
	void closed();

};

#endif
