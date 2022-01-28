//
// Created by amunra23 on 25.05.2021.
//

#ifndef DEFINE_H
#define DEFINE_H

#include <QTimer>
#include <QTextEdit>

#define BEGIN_FLOOR 1
#define END_FLOOR 20

#define TIMER_FLOOR_CROSS 1000
#define TIMER_LIFT_WAIT 1000
#define TIMER_DOOR_MOVE 1000

#define LINE_FOR_PRINT "\n----------------------------\n"

enum Direction
{
    UP = 1,
    STAY = 0,
    DOWN = -1
};

#endif //DEFINE_H
