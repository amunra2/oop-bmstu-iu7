#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "selector.h"
#include "draw_figure.h"

#define CV_WIDTH 770
#define CV_HEIGHT 600

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_load_clicked();

    void on_pushButton_spin_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_scale_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
