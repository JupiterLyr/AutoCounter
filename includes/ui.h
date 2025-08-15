#ifndef UI_H
#define UI_H

#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

namespace Ui {
    class MainWindow {
    public:
        void setupUi(QMainWindow* mainWindow);

        /// @hiderefs settings
        QSpinBox* f_set_box;
        QLineEdit* range_max;
        QLineEdit* range_min;

        /// @hiderefs control
        QPushButton* btn_start_count;
        QPushButton* btn_stop_count;

        /// @hiderefs display
        QLabel* common_show;
        QLCDNumber* lcd_show;
    };
}

#endif