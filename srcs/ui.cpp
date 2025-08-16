#include "ui.h"
#include <QtCore/qnamespace.h>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QIcon>
#include <QLayout>
#include <QMessageBox>
#include <iostream>

namespace Ui {
    void MainWindow::setupUi(QMainWindow* mainWindow) {
        QWidget* centralWidget = new QWidget(mainWindow);
        mainWindow->setCentralWidget(centralWidget);
        centralWidget->setFixedSize(400, 500);

        mainWindow->setWindowTitle("Auto Counter");
        QString iconPath = QDir(QCoreApplication::applicationDirPath()).filePath("resource/icon.png");
        if (QFileInfo::exists(iconPath))
            mainWindow->setWindowIcon(QIcon(iconPath));
        else
            QMessageBox::warning(nullptr, "Warning", "Icon file does not exist!");

        centralWidget->setStyleSheet(
            "QLabel, QSpinBox, QLineEdit, QPushButton { font-size: 14px; }"
        );
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
        QLabel* settingsTitle = new QLabel("Auto Counter Settings");
        settingsTitle->setStyleSheet("font-size: 16px;");
        settingsTitle->setAlignment(Qt::AlignCenter);
        QLabel* displayTitle = new QLabel("Digital Display Window");
        displayTitle->setStyleSheet("font-size: 16px;");
        displayTitle->setAlignment(Qt::AlignCenter);

        // 设置界面
        QVBoxLayout* settingsLayout = new QVBoxLayout();

        QHBoxLayout* freqLayout = new QHBoxLayout();
        freqLayout->setAlignment(Qt::AlignCenter);
        QLabel* f_set_note = new QLabel("Switching Frequency (Hz): ");
        f_set_box = new QSpinBox();
        f_set_box->setFixedWidth(100);
        f_set_box->setValue(25);
        f_set_box->setRange(1, 100);

        freqLayout->addStretch(1);
        freqLayout->addWidget(f_set_note, 8);
        freqLayout->addWidget(f_set_box, 2);
        freqLayout->addStretch(1);
        settingsLayout->addLayout(freqLayout);

        QHBoxLayout* rangeLayout1 = new QHBoxLayout();
        rangeLayout1->setAlignment(Qt::AlignCenter);
        QLabel* range_max_note = new QLabel("Maximum Count Value: ");
        range_max = new QLineEdit();
        range_max->setText("1000");
        range_max->setValidator(new QIntValidator(0, 99999999));
        range_max->setFixedWidth(100);
        QHBoxLayout* rangeLayout2 = new QHBoxLayout();
        rangeLayout2->setAlignment(Qt::AlignCenter);
        QLabel* range_min_note = new QLabel("Minimum Count Value: ");
        range_min = new QLineEdit();
        range_min->setText("0");
        range_min->setValidator(new QIntValidator(0, 99999999));
        range_min->setFixedWidth(100);

        rangeLayout1->addStretch(1);
        rangeLayout1->addWidget(range_max_note, 8);
        rangeLayout1->addWidget(range_max, 2);
        rangeLayout1->addStretch(1);
        settingsLayout->addLayout(rangeLayout1);
        rangeLayout2->addStretch(1);
        rangeLayout2->addWidget(range_min_note, 8);
        rangeLayout2->addWidget(range_min, 2);
        rangeLayout2->addStretch(1);
        settingsLayout->addLayout(rangeLayout2);

        // 控制按钮
        QHBoxLayout* ctrlBtnLayout = new QHBoxLayout();
        btn_start_count = new QPushButton("▶ Start");
        btn_start_count->setStyleSheet("font-size: 16px; color: green;");
        btn_start_count->setCursor(Qt::PointingHandCursor);
        btn_start_count->setFixedHeight(40);
        btn_stop_count = new QPushButton("■ Stop");
        btn_stop_count->setStyleSheet("font-size: 16px; color: red;");
        btn_stop_count->setCursor(Qt::PointingHandCursor);
        btn_stop_count->setFixedHeight(40);
        btn_stop_count->setDisabled(true);

        ctrlBtnLayout->addStretch(1);
        ctrlBtnLayout->addWidget(btn_start_count, 10);
        ctrlBtnLayout->addWidget(btn_stop_count, 10);
        ctrlBtnLayout->addStretch(1);

        // 显示界面
        QVBoxLayout* displayLayout = new QVBoxLayout();
        displayLayout->setAlignment(Qt::AlignCenter);
        common_show = new QLabel("0");
        common_show->setAlignment(Qt::AlignCenter);
        common_show->setStyleSheet("border: 1px solid gray; font-size: 56px;");
        common_show->setFixedSize(350, 80);
        lcd_show = new QLCDNumber();
        lcd_show->setDigitCount(8);
        lcd_show->setSegmentStyle(QLCDNumber::Flat);
        lcd_show->display("--------");
        lcd_show->setStyleSheet("border: 1px solid gray; color: red; background-color: #333333;");
        lcd_show->setFixedSize(350, 80);

        displayLayout->addWidget(common_show, 2);
        displayLayout->addWidget(lcd_show, 2);

        // 界面总组装
        mainLayout->addStretch(1);
        mainLayout->addWidget(settingsTitle);
        mainLayout->addStretch(1);
        mainLayout->addLayout(settingsLayout);
        mainLayout->addStretch(1);
        mainLayout->addLayout(ctrlBtnLayout);
        mainLayout->addStretch(1);
        mainLayout->addWidget(displayTitle);
        mainLayout->addStretch(1);
        mainLayout->addLayout(displayLayout);
        mainLayout->addStretch(1);
    }
}; // namespace Ui