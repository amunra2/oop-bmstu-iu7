//
// Created by amunra23 on 25.05.2021.
//

#include "../inc/door.h"

Door::Door()
{
    //qDebug() << "\tIn door";

    _state = CLOSED;

    QObject::connect(&_timer_open,  SIGNAL(timeout()), this, SLOT(slot_open()));
    QObject::connect(&_timer_wait,  SIGNAL(timeout()), this, SLOT(slot_closing()));
    QObject::connect(&_timer_close, SIGNAL(timeout()), this, SLOT(slot_close()));
}


void Door::slot_opening()
{
    // qDebug() << "\tIn opening" << __LINE__ << __FUNCTION__;

    if (CLOSED == _state || CLOSING == _state)
    {
        qDebug() << "Двери открываются";

        _state = OPENING;

        if (CLOSED == _state)
        {
            _timer_open.start(TIMER_DOOR_MOVE);
        }
        else
        {
            auto timer = _timer_close.remainingTime();
            _timer_close.stop();
            _timer_open.start(TIMER_DOOR_MOVE - timer);

        }
    }
}


//void Door::ready_to_go()
//{
//    if (CLOSED == _state)
//    {
//        emit signal_door_closed();
//    }
//}


void Door::slot_open()
{
    //qDebug() << "\tIn open" << __LINE__ << __FUNCTION__;

    if (OPENING != _state) { return; }

    _state = OPEN;
    qDebug() << "Двери открыты";

    _timer_wait.start(TIMER_DOOR_MOVE);
}


void Door::slot_closing()
{
    // qDebug() << "\tIn closing" << __LINE__ << __FUNCTION__;

    if (OPEN != _state) { return; }

    _state = CLOSING;
    qDebug() << "Двери закрываются";
    _timer_close.start(TIMER_DOOR_MOVE);
}


void Door::slot_close()
{
    // qDebug() << "\tIn close" << __LINE__ << __FUNCTION__;

    if (CLOSING != _state) { return; }

    _state = CLOSED;
    qDebug() << "Двери закрыты\n";

    emit signal_door_closed();
}



