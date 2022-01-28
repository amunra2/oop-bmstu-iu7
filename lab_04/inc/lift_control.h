//
// Created by amunra23 on 25.05.2021.
//

#ifndef LIFT_CONTROL_H
#define LIFT_CONTROL_H

#include <QVBoxLayout>
#include <QObject>
#include <QWidget>
#include <QDebug>

#include <memory>
#include <vector>

#include "define.h"
#include "button.h"

class Controller : public QWidget
{
    Q_OBJECT

    enum ControllerIs
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

signals:
    void signal_new_target(int floor);
    void signal_stop(bool f, int t = 1);

public slots:
    void slot_new_target(int floor);
    void slot_pass_floor(int floor, Direction direction);

private:
    bool is_target(int &new_floor);

    int _floor{};
    int _need_floor{};

    ControllerIs _state;
    Direction _direction;

    std::vector<std::shared_ptr<Button>> _buttons;
    std::vector<bool> _visit_floors;
    std::unique_ptr<QVBoxLayout> _layout;
};

#endif //LIFT_CONTROL_H
