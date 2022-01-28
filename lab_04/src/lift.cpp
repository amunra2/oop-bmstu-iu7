//
// Created by amunra23 on 25.05.2021.
//

#include "../inc/lift.h"


Lift::Lift(QObject *parent) : QObject(parent)
{
    //qDebug() << "\tIn Lift";

    _controller.setStyleSheet("background-color:green;");

    QObject::connect(&_controller, SIGNAL(signal_new_target(int)), &_cabin, SLOT(cabin_target(int)));
    QObject::connect(&_cabin, SIGNAL(signal_pass_floor(int,Direction)), &_controller, SLOT(slot_pass_floor(int,Direction)));
    QObject::connect(&_controller, SIGNAL(signal_stop(bool,int)), &_cabin, SLOT(cabin_stop(bool,int)));
}


QWidget *Lift::widget()
{
    return &this->_controller;
}
