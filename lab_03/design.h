/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGN_H
#define DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_move;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *doubleSpinBox_scale_x;
    QDoubleSpinBox *doubleSpinBox_scale_y;
    QDoubleSpinBox *doubleSpinBox_scale_z;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_scale;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QDoubleSpinBox *doubleSpinBox_spin_x;
    QDoubleSpinBox *doubleSpinBox_spin_y;
    QDoubleSpinBox *doubleSpinBox_spin_z;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_spin;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_del_model_all;
    QComboBox *comboBox_models;
    QPushButton *pushButton_del_model_cur;
    QPushButton *pushButton_load_model;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_8;
    QComboBox *comboBox_cameras;
    QPushButton *pushButton_del_camera_cur;
    QGroupBox *groupBox_9;
    QPushButton *pushButton_camera_move_right;
    QPushButton *pushButton_camera_move_left;
    QPushButton *pushButton_camera_move_up;
    QPushButton *pushButton_camera_move_down;
    QPushButton *pushButton_add_camera;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1232, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 751, 651));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(770, 10, 461, 411));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 30, 141, 181));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(50, 20, 71, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_move_x = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        QFont font;
        font.setPointSize(12);
        doubleSpinBox_move_x->setFont(font);

        verticalLayout_3->addWidget(doubleSpinBox_move_x);

        doubleSpinBox_move_y = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        doubleSpinBox_move_y->setFont(font);

        verticalLayout_3->addWidget(doubleSpinBox_move_y);

        doubleSpinBox_move_z = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        doubleSpinBox_move_z->setFont(font);

        verticalLayout_3->addWidget(doubleSpinBox_move_z);

        verticalLayoutWidget_4 = new QWidget(groupBox_3);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 31, 101));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_4->addWidget(label_6);

        pushButton_move = new QPushButton(groupBox_3);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(10, 140, 121, 25));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(160, 30, 141, 181));
        verticalLayoutWidget_5 = new QWidget(groupBox_4);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(50, 20, 71, 101));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_scale_x = new QDoubleSpinBox(verticalLayoutWidget_5);
        doubleSpinBox_scale_x->setObjectName(QString::fromUtf8("doubleSpinBox_scale_x"));
        doubleSpinBox_scale_x->setFont(font);

        verticalLayout_5->addWidget(doubleSpinBox_scale_x);

        doubleSpinBox_scale_y = new QDoubleSpinBox(verticalLayoutWidget_5);
        doubleSpinBox_scale_y->setObjectName(QString::fromUtf8("doubleSpinBox_scale_y"));
        doubleSpinBox_scale_y->setFont(font);

        verticalLayout_5->addWidget(doubleSpinBox_scale_y);

        doubleSpinBox_scale_z = new QDoubleSpinBox(verticalLayoutWidget_5);
        doubleSpinBox_scale_z->setObjectName(QString::fromUtf8("doubleSpinBox_scale_z"));
        doubleSpinBox_scale_z->setFont(font);

        verticalLayout_5->addWidget(doubleSpinBox_scale_z);

        verticalLayoutWidget_6 = new QWidget(groupBox_4);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 20, 31, 101));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_6->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_6->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_6->addWidget(label_9);

        pushButton_scale = new QPushButton(groupBox_4);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(0, 140, 141, 25));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(310, 30, 141, 181));
        verticalLayoutWidget_7 = new QWidget(groupBox_5);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(50, 20, 71, 101));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_spin_x = new QDoubleSpinBox(verticalLayoutWidget_7);
        doubleSpinBox_spin_x->setObjectName(QString::fromUtf8("doubleSpinBox_spin_x"));
        doubleSpinBox_spin_x->setFont(font);

        verticalLayout_7->addWidget(doubleSpinBox_spin_x);

        doubleSpinBox_spin_y = new QDoubleSpinBox(verticalLayoutWidget_7);
        doubleSpinBox_spin_y->setObjectName(QString::fromUtf8("doubleSpinBox_spin_y"));
        doubleSpinBox_spin_y->setFont(font);

        verticalLayout_7->addWidget(doubleSpinBox_spin_y);

        doubleSpinBox_spin_z = new QDoubleSpinBox(verticalLayoutWidget_7);
        doubleSpinBox_spin_z->setObjectName(QString::fromUtf8("doubleSpinBox_spin_z"));
        doubleSpinBox_spin_z->setFont(font);

        verticalLayout_7->addWidget(doubleSpinBox_spin_z);

        verticalLayoutWidget_8 = new QWidget(groupBox_5);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(10, 20, 31, 101));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        verticalLayout_8->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        verticalLayout_8->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        verticalLayout_8->addWidget(label_12);

        pushButton_spin = new QPushButton(groupBox_5);
        pushButton_spin->setObjectName(QString::fromUtf8("pushButton_spin"));
        pushButton_spin->setGeometry(QRect(10, 140, 121, 25));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(50, 220, 371, 121));
        pushButton_del_model_all = new QPushButton(groupBox_6);
        pushButton_del_model_all->setObjectName(QString::fromUtf8("pushButton_del_model_all"));
        pushButton_del_model_all->setGeometry(QRect(20, 90, 321, 25));
        comboBox_models = new QComboBox(groupBox_6);
        comboBox_models->setObjectName(QString::fromUtf8("comboBox_models"));
        comboBox_models->setGeometry(QRect(90, 30, 201, 25));
        pushButton_del_model_cur = new QPushButton(groupBox_6);
        pushButton_del_model_cur->setObjectName(QString::fromUtf8("pushButton_del_model_cur"));
        pushButton_del_model_cur->setGeometry(QRect(20, 60, 321, 25));
        pushButton_load_model = new QPushButton(groupBox);
        pushButton_load_model->setObjectName(QString::fromUtf8("pushButton_load_model"));
        pushButton_load_model->setGeometry(QRect(98, 360, 271, 25));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(770, 420, 451, 251));
        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(210, 60, 191, 91));
        comboBox_cameras = new QComboBox(groupBox_8);
        comboBox_cameras->setObjectName(QString::fromUtf8("comboBox_cameras"));
        comboBox_cameras->setGeometry(QRect(40, 30, 121, 25));
        pushButton_del_camera_cur = new QPushButton(groupBox_8);
        pushButton_del_camera_cur->setObjectName(QString::fromUtf8("pushButton_del_camera_cur"));
        pushButton_del_camera_cur->setGeometry(QRect(10, 60, 171, 25));
        groupBox_9 = new QGroupBox(groupBox_7);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(30, 40, 131, 121));
        pushButton_camera_move_right = new QPushButton(groupBox_9);
        pushButton_camera_move_right->setObjectName(QString::fromUtf8("pushButton_camera_move_right"));
        pushButton_camera_move_right->setGeometry(QRect(80, 60, 31, 25));
        pushButton_camera_move_left = new QPushButton(groupBox_9);
        pushButton_camera_move_left->setObjectName(QString::fromUtf8("pushButton_camera_move_left"));
        pushButton_camera_move_left->setGeometry(QRect(20, 60, 31, 25));
        pushButton_camera_move_up = new QPushButton(groupBox_9);
        pushButton_camera_move_up->setObjectName(QString::fromUtf8("pushButton_camera_move_up"));
        pushButton_camera_move_up->setGeometry(QRect(50, 30, 31, 25));
        pushButton_camera_move_down = new QPushButton(groupBox_9);
        pushButton_camera_move_down->setObjectName(QString::fromUtf8("pushButton_camera_move_down"));
        pushButton_camera_move_down->setGeometry(QRect(50, 90, 31, 25));
        pushButton_add_camera = new QPushButton(groupBox_7);
        pushButton_add_camera->setObjectName(QString::fromUtf8("pushButton_add_camera"));
        pushButton_add_camera->setGeometry(QRect(140, 200, 171, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        pushButton_move->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "kx:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "ky:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "kz:", nullptr));
        pushButton_scale->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        pushButton_spin->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        pushButton_del_model_all->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        pushButton_del_model_cur->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", nullptr));
        pushButton_load_model->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        groupBox_8->setTitle(QString());
        pushButton_del_camera_cur->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        pushButton_camera_move_right->setText(QApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_camera_move_left->setText(QApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_camera_move_up->setText(QApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_camera_move_down->setText(QApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_add_camera->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
