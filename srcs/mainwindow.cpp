#include "mainwindow.h"

#include <QtCore/qlogging.h>
#include <QtCore/qnamespace.h>

#include <iostream>
#include <string>
#include <QMessageBox>
#include <QThread>
#include <QWidget>

#include "ui.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    std::cout << "MainWindow threadId: " << QThread::currentThreadId() << std::endl;
    ui = new Ui::MainWindow();
    ui->setupUi(this);

    // 计数器的计时器初始化
    cTimer = new QTimer(this);
    connect(cTimer, &QTimer::timeout, this, &MainWindow::onTick);

    // 控制按钮信号连接
    connect(ui->btn_start_count, &QPushButton::clicked, this, &MainWindow::onStartCount);
    connect(ui->btn_stop_count, &QPushButton::clicked, this, &MainWindow::onStopCount);
}

MainWindow::~MainWindow() {
    delete ui;
}

/// @brief 点击 Start 开始计数
void MainWindow::onStartCount() {
    cMax = ui->range_max->text().toInt();
    cMin = ui->range_min->text().toInt();
    if (cMax < cMin) {
        QMessageBox::critical(this, "Error", "Maximum must be greater than minimum!");
        return;
    }
    // 初始化状态
    ui->btn_start_count->setDisabled(true);
    ui->btn_stop_count->setDisabled(false);
    cCount = cMin;
    ui->common_show->setText(QString::number(cCount));
    ui->lcd_show->display(cCount);

    // 每隔 interval 触发一次
    int interval = static_cast<int>(1000.0 / ui->f_set_box->value());
    cTimer->start(interval);
}

/// @brief 点击 Stop 停止计数
void MainWindow::onStopCount() {
    cTimer->stop();
    ui->btn_start_count->setDisabled(false);
    ui->btn_stop_count->setDisabled(true);
}

/// @brief 利用 QTimer 自动调用更新
void MainWindow::onTick() {
    if (++cCount > cMax)
        cCount = cMin;
    ui->common_show->setText(QString::number(cCount));
    ui->lcd_show->display(cCount);
}
