#include "mainwindow.h"

#include <QtCore/qlogging.h>
#include <QtCore/qnamespace.h>

#include <iostream>
#include <QThread>
#include <QWidget>

#include "ui.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    std::cout << "MainWindow threadId: " << QThread::currentThreadId() << std::endl;
    ui = new Ui::MainWindow();
    ui->setupUi(this);

    connect(ui->btn_start_count, &QPushButton::clicked, this, &MainWindow::onStartCount);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartCount() {
    /// TODO: 1. 检查输入框内容是否合法
    /// TODO: 2. 禁用Start，启用Stop
    /// TODO: 3. 利用QTimer控制数字增减
    ;
    /// TODO: 4. 复位条件
}
