/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_SerialPortState;
    QComboBox *comboBox_SerialPorts;
    QPushButton *pushButton_UpdateFirmware;
    QPushButton *pushButton_SelectFirmware;
    QLabel *label_15;
    QTextEdit *textEdit;
    QLabel *label_Version;
    QPushButton *pushButton_RefreshSerialPorts;
    QTextEdit *textEdit_Firmware;
    QGridLayout *gridLayout_9;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QSlider *horizontalSlider;
    QLabel *label_8;
    QLabel *label_11;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *widget_3;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(890, 560);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(200, 100));
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(180, 160));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(14);
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_7, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(220, 160));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        groupBox_2->setFont(font2);
        groupBox_2->setStyleSheet(QStringLiteral(""));
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font2);
        label_12->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_8->addWidget(label_12, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font2);
        label_13->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_8->addWidget(label_13, 2, 0, 1, 1);

        label_SerialPortState = new QLabel(groupBox_2);
        label_SerialPortState->setObjectName(QStringLiteral("label_SerialPortState"));
        label_SerialPortState->setFont(font2);
        label_SerialPortState->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));
        label_SerialPortState->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_SerialPortState, 2, 2, 1, 1);

        comboBox_SerialPorts = new QComboBox(groupBox_2);
        comboBox_SerialPorts->setObjectName(QStringLiteral("comboBox_SerialPorts"));

        gridLayout_8->addWidget(comboBox_SerialPorts, 1, 2, 1, 1);

        pushButton_UpdateFirmware = new QPushButton(groupBox_2);
        pushButton_UpdateFirmware->setObjectName(QStringLiteral("pushButton_UpdateFirmware"));

        gridLayout_8->addWidget(pushButton_UpdateFirmware, 5, 2, 1, 1);

        pushButton_SelectFirmware = new QPushButton(groupBox_2);
        pushButton_SelectFirmware->setObjectName(QStringLiteral("pushButton_SelectFirmware"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        pushButton_SelectFirmware->setFont(font3);

        gridLayout_8->addWidget(pushButton_SelectFirmware, 4, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setFont(font2);
        label_15->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_8->addWidget(label_15, 3, 0, 1, 1);

        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(0, 32));

        gridLayout_8->addWidget(textEdit, 6, 0, 1, 3);

        label_Version = new QLabel(groupBox_2);
        label_Version->setObjectName(QStringLiteral("label_Version"));
        label_Version->setFont(font2);
        label_Version->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_8->addWidget(label_Version, 0, 0, 1, 3);

        pushButton_RefreshSerialPorts = new QPushButton(groupBox_2);
        pushButton_RefreshSerialPorts->setObjectName(QStringLiteral("pushButton_RefreshSerialPorts"));

        gridLayout_8->addWidget(pushButton_RefreshSerialPorts, 5, 0, 1, 1);

        textEdit_Firmware = new QTextEdit(groupBox_2);
        textEdit_Firmware->setObjectName(QStringLiteral("textEdit_Firmware"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit_Firmware->sizePolicy().hasHeightForWidth());
        textEdit_Firmware->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(textEdit_Firmware, 3, 2, 2, 1);


        gridLayout_7->addWidget(groupBox_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_7, 2, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(250, 250));
        label->setMaximumSize(QSize(250, 250));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_9, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(260, 200));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSlider = new QSlider(widget_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy5);
        horizontalSlider->setMouseTracking(true);
        horizontalSlider->setStyleSheet(QStringLiteral(""));
        horizontalSlider->setMaximum(20);
        horizontalSlider->setPageStep(0);
        horizontalSlider->setSliderPosition(5);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setProperty("tabletTracking", QVariant(true));

        gridLayout_4->addWidget(horizontalSlider, 2, 0, 1, 6);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy6);
        label_11->setMinimumSize(QSize(120, 0));
        QFont font4;
        font4.setFamily(QStringLiteral("Ubuntu"));
        font4.setPointSize(20);
        label_11->setFont(font4);
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setStyleSheet(QStringLiteral("color: rgb(245, 121, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 6);

        horizontalSlider_2 = new QSlider(widget_2);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        sizePolicy5.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy5);
        horizontalSlider_2->setMouseTracking(true);
        horizontalSlider_2->setMaximum(4000);
        horizontalSlider_2->setPageStep(0);
        horizontalSlider_2->setSliderPosition(1000);
        horizontalSlider_2->setTracking(true);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setProperty("tabletTracking", QVariant(true));

        gridLayout_4->addWidget(horizontalSlider_2, 4, 0, 1, 6);

        horizontalSlider_3 = new QSlider(widget_2);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        sizePolicy5.setHeightForWidth(horizontalSlider_3->sizePolicy().hasHeightForWidth());
        horizontalSlider_3->setSizePolicy(sizePolicy5);
        horizontalSlider_3->setMouseTracking(true);
        horizontalSlider_3->setStyleSheet(QStringLiteral(""));
        horizontalSlider_3->setMaximum(4000);
        horizontalSlider_3->setPageStep(0);
        horizontalSlider_3->setSliderPosition(2000);
        horizontalSlider_3->setTracking(true);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setProperty("tabletTracking", QVariant(true));

        gridLayout_4->addWidget(horizontalSlider_3, 6, 0, 1, 6);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_4->addWidget(label_9, 3, 0, 1, 1);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(243, 243, 243);"));

        gridLayout_4->addWidget(label_10, 5, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy5.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy5);
        gridLayout_5 = new QGridLayout(widget_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_Start = new QPushButton(widget_3);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setFont(font1);
        pushButton_Start->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(pushButton_Start, 0, 0, 1, 1);

        pushButton_Stop = new QPushButton(widget_3);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setFont(font1);
        pushButton_Stop->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(pushButton_Stop, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_3, 7, 0, 1, 6);


        gridLayout->addWidget(widget_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 890, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BLDC_FAN", 0));
        groupBox->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "Imx.6ull", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256:", 0));
        label_7->setText(QApplication::translate("MainWindow", "BLDC_FOC_FAN", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\271\263\345\217\260:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Mymymind", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215:", 0));
        groupBox_2->setTitle(QString());
        label_12->setText(QApplication::translate("MainWindow", "\350\231\232\346\213\237\344\270\262\345\217\243\345\217\267\357\274\232", 0));
        label_13->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", 0));
        label_SerialPortState->setText(QApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245", 0));
        pushButton_UpdateFirmware->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\233\264\346\226\260\345\233\272\344\273\266", 0));
        pushButton_SelectFirmware->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\272\344\273\266", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\233\272\344\273\266\350\267\257\345\276\204\357\274\232", 0));
        label_Version->setText(QApplication::translate("MainWindow", "\345\233\272\344\273\266\346\233\264\346\226\260\357\274\232", 0));
        pushButton_RefreshSerialPorts->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\350\231\232\346\213\237\344\270\262\345\217\243", 0));
        label->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", 0));
        label_11->setText(QApplication::translate("MainWindow", "\346\227\240\345\210\267\345\260\217\351\243\216\346\211\207\346\216\247\345\210\266\345\217\260", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246:", 0));
        label_10->setText(QApplication::translate("MainWindow", "\345\271\205\345\272\246:", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
