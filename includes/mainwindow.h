#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

// 确保 Ui 命名空间的前向声明正确
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    // Q_OBJECT  // 需要用到信号和槽时要加回来

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void onStartCount();
    void onStopCount();

private:
    Ui::MainWindow* ui;

    QTimer* cTimer = nullptr;
    int cMax = 1000, cMin = 0, cCount = 0;

private slots:
    void onTick();
};
#endif