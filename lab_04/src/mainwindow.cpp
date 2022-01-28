#include <memory>

#include "../inc/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setFixedSize(500, 500);
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);

    ui->centralwidget->setLayout(this->_layout.get());

    _layout->addWidget(this->_lift.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

