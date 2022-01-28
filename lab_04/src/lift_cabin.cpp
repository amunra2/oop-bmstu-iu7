//
// Created by amunra23 on 25.05.2021.
//

#include "../inc/lift_cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    //qDebug() << "\tIn cabin";

    _state = FREE_CLOSE;
    _floor = 1;
    _need_floor = 1;
    _direction = STAY;

    _is_last = false;

    //QObject::connect(this, SIGNAL(signal_move()), &_door, SLOT(ready_to_go()));
    QObject::connect(this, SIGNAL(signal_stop(bool,int)), this, SLOT(cabin_stop(bool,int)));
    QObject::connect(this, SIGNAL(signal_door_open()), &_door, SLOT(slot_opening()));
    QObject::connect(&_timer_cabin_move, SIGNAL(timeout()), this, SLOT(cabin_move()));

    QObject::connect(&_door, SIGNAL(signal_door_closed()), this, SLOT(ready()));
    QObject::connect(this, SIGNAL(signal_ready_to_move()), this, SLOT(cabin_move()));
}


void Cabin::cabin_move()
{
    // qDebug() << "\tIn cabin_move" << __LINE__ << __FUNCTION__;
    // qDebug() << "\t\t\t" << _state << FREE_CLOSE << FREE_OPEN << MOVE << WAIT;

    if (MOVE == _state || WAIT == _state)
    {
        _state = MOVE;

        _timer_cabin_move.start(TIMER_FLOOR_CROSS);

        qDebug() << "Лифт в пути. Текущий этаж # " << _floor;

        emit signal_pass_floor(_floor, _direction);

        if (_floor == _need_floor) { return; }

        if (_floor > _need_floor)
        {
            _direction = DOWN;
            _floor -= 1;
        }
        else
        {
            _direction = UP;
            _floor += 1;
        }
    }
}

void Cabin::cabin_target(int floor)
{
    // qDebug() << "\tIn cabin_target" << __LINE__ << __FUNCTION__;
    // qDebug() << "\t\t\t" << _state << FREE_CLOSE << FREE_OPEN << MOVE << WAIT;

    if (FREE_OPEN == _state)
    {
        if (FREE_OPEN == _state)
        {
            _state = WAIT;
            _need_floor = floor;
        }
//        _state = WAIT;
//        _need_floor = floor;

        if (_floor == _need_floor)
        {
            emit signal_pass_floor(_floor, _direction);
        }
        else
        {
            if (_need_floor > _floor)
            {
                _direction = UP;
            }
            else
            {
                _direction = DOWN;
            }

            return;
            //emit signal_move();
        }
    }

    if (FREE_CLOSE == _state)
    {
        if (FREE_CLOSE == _state)
        {
            _state = WAIT;
            _need_floor = floor;
        }
//        _state = WAIT;
//        _need_floor = floor;

        if (_floor == _need_floor)
        {
            emit signal_pass_floor(_floor, _direction);
        }
        else
        {
            if (_need_floor > _floor)
            {
                _direction = UP;
            }
            else
            {
                _direction = DOWN;
            }

            emit signal_ready_to_move();
            //emit signal_move();
        }
    }
}

void Cabin::ready()
{
    // qDebug() << "\tIn cabin_ready" << __LINE__ << __FUNCTION__;

//    if (_is_last)
//    {
//        _state = FREE_CLOSE;
//    }
//    else
//    {
//        _state = WAIT;
//    }

    _state = FREE_CLOSE;

    // qDebug() << "\t\t\t" << _state << FREE_CLOSE;

    emit signal_ready_to_move();
}

void Cabin::cabin_stop(bool last, int floor)
{
    // qDebug() << "\tIn cabin_stop" << __LINE__ << __FUNCTION__;

    //_is_last = last;
//
//    if (!_is_last)
//    {
//        _need_floor = floor;
//    }

    if (last)
    {
        _state = FREE_OPEN;
    }
    else
    {
        _state = WAIT;
    }

    _timer_cabin_move.stop();

    emit signal_door_open();
}
