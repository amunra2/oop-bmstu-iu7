//
// Created by amunra23 on 25.05.2021.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>


class Button : public QPushButton
{
    Q_OBJECT;

    enum ButtonIs
    {
        ACTIVE,
        INACTIVE
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() override = default;

    void set_floor(const int &floor);
    int get_floor() const;

signals:
    void signal_press(int floor);
    void signal_unpress();


public slots:
    void slot_press();
    void slot_unpress();


private:
    ButtonIs _state;

    int _floor;
};

#endif //BUTTON_H
