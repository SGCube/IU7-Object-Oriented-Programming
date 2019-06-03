#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT
public:
	Doors(QObject *parent = nullptr);
	~Doors();

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
    static const size_t standTime = 5000;
	
signals:
    void sendClosed();
	
	// messages
	void msgOpened();
	void msgClosing();
	void msgOpening();

public slots:
    void startOpening();
	void opened();
    void startClosing();
	void closed();
};

#endif
