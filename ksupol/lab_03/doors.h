#ifndef DOORS_H
#define DOORS_H

#define MOVING_ONE_FLOOR_TIME 1500
#define DOORS_CLOSE_OPEN 1000
#define DOORS_OPEN_TIME 2000

#include <QObject>
#include "diraction.h"

class Doors : public QObject
{
    Q_OBJECT
    enum doors_state
    {
        OPENED,
        CLOSED,
        OPENNING,
        CLOSING
    };

public:
    explicit Doors(QObject *parent = nullptr);
    void set_text(QTextEdit *t);

signals:
    void closeddoors();
    void openeddoors();

public slots:
    void start_openning();
    void start_closing();
private slots:
    void open();
    void close();

private:
    doors_state current_state;
    QTextEdit *text;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
    QTimer doors_stay_open_timer;
};

#endif // LIFTDOORS_H
