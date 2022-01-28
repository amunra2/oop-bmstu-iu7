//
// Created by amunra23 on 25.05.2021.
//

#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <qdebug.h>

#include "define.h"

class Door : public QObject
{
    Q_OBJECT

    enum DoorIs
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSED
    };

public:
    Door();
    ~Door() = default;

signals:
    void signal_door_closed();

private slots:
    void slot_open();
    void slot_opening();
    void slot_closing();
    void slot_close();

    //void ready_to_go();

private:
    DoorIs _state;

    QTimer _timer_open;
    QTimer _timer_close;
    QTimer _timer_wait;
};

#endif //DOOR_H
