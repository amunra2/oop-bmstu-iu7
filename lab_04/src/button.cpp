//
// Created by amunra23 on 25.05.2021.
//

#include "../inc/button.h"
#include "../inc/define.h"

#include <qdebug.h>


Button::Button(QWidget *parent) : QPushButton(parent)
{
    //qDebug() << "\tIn Button";

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(slot_press()));
    QObject::connect(this, SIGNAL(signal_unpress()), this, SLOT(slot_unpress()));

    this->_state = INACTIVE;
    this->_floor = 1;
}


void Button::set_floor(const int &floor)
{
    _floor = floor;
}

void Button::slot_press()
{
    //qDebug() << "\tIn slot_press" << __LINE__ << __FUNCTION__;

    if (INACTIVE != _state) { return; }

    // qDebug() << LINE_FOR_PRINT << "Вызван лифт на этаж # " << get_floor() << LINE_FOR_PRINT;

    this->setStyleSheet("background-color:orange;");
    this->update();

    this->_state = ACTIVE;
    this->setDisabled(true);

    emit signal_press(get_floor());
}

int Button::get_floor() const
{
    return _floor;
}

void Button::slot_unpress()
{
    //qDebug() << "\tIn slot_unpress" << __LINE__ << __FUNCTION__;

    if (ACTIVE != _state) { return; }

    this->setStyleSheet("background-color:green;");
    this->update();

    this->_state = INACTIVE;
    this->setDisabled(false);
}




