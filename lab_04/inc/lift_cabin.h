//
// Created by amunra23 on 25.05.2021.
//

#ifndef LIFT_CABIN_H
#define LIFT_CABIN_H

#include <QObject>

#include "door.h"
#include "lift_control.h"


class Cabin : public QObject
{
    Q_OBJECT

    enum CabinIs
    {
        FREE_OPEN,
        FREE_CLOSE,
        WAIT,
        MOVE
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() override = default;

signals:
    void signal_door_open();
    void signal_pass_floor(int floor, Direction direction);
    void signal_move();
    void signal_stop(bool = true, int = 1);

    void signal_ready_to_move();

public slots:
    void cabin_move();
    void cabin_target(int floor);
    void cabin_stop(bool last, int floor = 1);

    void ready();

private:
    int _floor;
    int _need_floor;
    bool _is_last;

    Door _door;
    Direction _direction;
    CabinIs _state;

    QTimer _timer_cabin_move;
};



#endif //LIFT_CABIN_H
