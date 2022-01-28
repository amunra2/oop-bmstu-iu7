//
// Created by amunra23 on 25.05.2021.
//

#ifndef LIFT_H
#define LIFT_H

#include <QObject>

#include "define.h"
#include "lift_cabin.h"
#include "lift_control.h"

class Lift : public QObject
{
    Q_OBJECT

public:
    explicit Lift(QObject *parent = nullptr);
    ~Lift() override = default;

    QWidget *widget();

private:
    Cabin _cabin;
    Controller _controller;
};

#endif //LIFT_H
