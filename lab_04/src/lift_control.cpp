//
// Created by amunra23 on 25.05.2021.
//

#include "../inc/lift_control.h"

#include <memory>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    //qDebug() << "\tIn Controller" << __LINE__ << __FILE__;

    _layout = std::make_unique<QVBoxLayout>();

    setLayout(_layout.get());

    for (int i = 0; i < END_FLOOR; i++)
    {
        std::shared_ptr<Button> new_btn(new Button);

        new_btn->set_floor(END_FLOOR - i);
        new_btn->setText(QString::number(END_FLOOR - i));

        _buttons.insert(_buttons.begin(), new_btn);

        _layout->addWidget(dynamic_cast<QPushButton*>(new_btn.get()));

        _visit_floors.push_back(true);

        QObject::connect(new_btn.get(), SIGNAL(signal_press(int)), this, SLOT(slot_new_target(int)));
    }

}

void Controller::slot_new_target(int floor)
{
    //qDebug() << "\tIn slot_new_target" << __LINE__ << __FUNCTION__;

    _state = BUSY;
    _visit_floors[floor - 1] = false;

    is_target(floor);

    _need_floor = floor;

    emit signal_new_target(floor);
}

void Controller::slot_pass_floor(int floor, Direction direction)
{
    //qDebug() << "\tIn slot_pass_floor" << __LINE__ << __FUNCTION__;

    if (BUSY != _state) { return; }

    _floor = floor;
    _direction = direction;

    if (_floor != _need_floor) { return; }

    qDebug() << LINE_FOR_PRINT << "Лифт прибыл на этаж # " << _floor << LINE_FOR_PRINT;

    emit _buttons[floor - 1]->signal_unpress();
    _visit_floors[floor - 1] = true;

    if (is_target(floor))
    {
        _need_floor = floor;
        emit signal_stop(false, floor);
    }
    else
    {
        _state = FREE;
        emit signal_stop(true);
    }
}

bool Controller::is_target(int &new_floor)
{
    //qDebug() << "\tIn be_target" << __LINE__ << __FUNCTION__;

    int direction = _direction;

    int ind = 0;

    for (int i = _floor - 1; i >= 0 && i < END_FLOOR; i += direction)
    {
        if (!_visit_floors[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    for (int i = _floor - 1; i >= 0 && i < END_FLOOR; i -= direction)
    {
        if (!_visit_floors[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    return false;
}

