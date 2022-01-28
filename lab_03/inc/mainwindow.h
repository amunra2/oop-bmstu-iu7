#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "design.h"

#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QMessageBox>
#include <QGraphicsScene>
#include <QFileDialog>

#include "commands/base_command.h"
#include "commands/viewer_command.h"
#include "commands/model_command.h"
#include "commands/scene_command.h"
#include "exceptions.h"
#include "drawer/abstract_drawer_factory.h"
#include "drawer/drawer_qt_factory.h"
#include "facade/facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void on_pushButton_move_clicked();

    void on_pushButton_scale_clicked();

    void on_pushButton_spin_clicked();

    void on_pushButton_del_model_cur_clicked();

    void on_pushButton_del_model_all_clicked();

    void on_pushButton_load_model_clicked();

    void on_pushButton_camera_move_up_clicked();

    void on_pushButton_camera_move_left_clicked();

    void on_pushButton_camera_move_down_clicked();

    void on_pushButton_camera_move_right_clicked();

    void on_pushButton_del_camera_cur_clicked();

    void on_pushButton_add_camera_clicked();

    void change_cam();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void setup_scene();
    void update_scene();
    void check_cam_exist();
    void check_can_delete_cam();
    void check_models_exist();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *_scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<AbstractDrawer> _drawer;
};
#endif // MAINWINDOW_H
