/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *chatDisplay;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QComboBox *profileDropdown;
    QSlider *brightnessSlider;
    QSlider *fontSizeSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *brightnessInput;
    QLineEdit *fontSizeInput;
    QLabel *brightnessRangeLabel;
    QLabel *fontSizeRangeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        chatDisplay = new QTextEdit(centralwidget);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setGeometry(QRect(20, 90, 441, 351));
        QFont font;
        font.setPointSize(18);
        chatDisplay->setFont(font);
        chatDisplay->setReadOnly(true);
        messageInput = new QLineEdit(centralwidget);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(20, 450, 311, 51));
        messageInput->setFont(font);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(350, 450, 100, 41));
        sendButton->setFont(font);
        profileDropdown = new QComboBox(centralwidget);
        profileDropdown->setObjectName("profileDropdown");
        profileDropdown->setGeometry(QRect(490, 90, 131, 61));
        profileDropdown->setFont(font);
        brightnessSlider = new QSlider(centralwidget);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setGeometry(QRect(490, 150, 141, 31));
        brightnessSlider->setOrientation(Qt::Orientation::Horizontal);
        fontSizeSlider = new QSlider(centralwidget);
        fontSizeSlider->setObjectName("fontSizeSlider");
        fontSizeSlider->setGeometry(QRect(490, 300, 141, 31));
        fontSizeSlider->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 701, 61));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 230, 201, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(490, 380, 191, 41));
        brightnessInput = new QLineEdit(centralwidget);
        brightnessInput->setObjectName("brightnessInput");
        brightnessInput->setGeometry(QRect(490, 180, 113, 21));
        fontSizeInput = new QLineEdit(centralwidget);
        fontSizeInput->setObjectName("fontSizeInput");
        fontSizeInput->setGeometry(QRect(490, 330, 113, 21));
        brightnessRangeLabel = new QLabel(centralwidget);
        brightnessRangeLabel->setObjectName("brightnessRangeLabel");
        brightnessRangeLabel->setGeometry(QRect(490, 200, 201, 31));
        fontSizeRangeLabel = new QLabel(centralwidget);
        fontSizeRangeLabel->setObjectName("fontSizeRangeLabel");
        fontSizeRangeLabel->setGeometry(QRect(490, 350, 191, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Chat App for Seniors", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Font Size", nullptr));
        brightnessInput->setPlaceholderText(QString());
        fontSizeInput->setPlaceholderText(QString());
        brightnessRangeLabel->setText(QCoreApplication::translate("MainWindow", "Min: 50% Max: 150%", nullptr));
        fontSizeRangeLabel->setText(QCoreApplication::translate("MainWindow", "Min: 10pt Max: 30pt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
