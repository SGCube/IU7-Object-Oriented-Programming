#ifndef CONTROL_BOARD_H
#define CONTROL_BOARD_H

#include <QObject>
#include <QVector>
#include "diraction.h"

class Control_board : public QObject
{
    Q_OBJECT
    enum cp_state
    {
        FREE,
        BUSY
    };

public:
    explicit Control_board(QObject *parent = nullptr);
    void set_new_target(int floor);
    void set_text(QTextEdit *t);

signals:
    void set_target(int floor);

public slots:
    void achieved_floor(int floor);
    void passed_floor(int floor, direction d);

private:
    int current_floor;
    bool targets[FLOORS_NUMBERS];
    cp_state current_state;
    direction current_direction;
    bool next_target(int &floor);

    QTextEdit *text;
};

#endif // CONTROL_BOARD_H
