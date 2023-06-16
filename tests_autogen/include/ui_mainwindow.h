/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *first_player;
    QLabel *vs;
    QLabel *second_player;
    QPushButton *restart;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 500));
        MainWindow->setMaximumSize(QSize(800, 900));
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton[cell=true]{\n"
"        font-size: 30px;\n"
"        min-height: 20px;\n"
"        max-height: 100px;\n"
"        min-width: 20px;\n"
"        max-width: 100px;\n"
"        }\n"
"    "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        first_player = new QLabel(centralwidget);
        first_player->setObjectName("first_player");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(first_player->sizePolicy().hasHeightForWidth());
        first_player->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        first_player->setFont(font);
        first_player->setStyleSheet(QString::fromUtf8("color: red; font-weight: 700;"));
        first_player->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(first_player);

        vs = new QLabel(centralwidget);
        vs->setObjectName("vs");
        sizePolicy1.setHeightForWidth(vs->sizePolicy().hasHeightForWidth());
        vs->setSizePolicy(sizePolicy1);
        vs->setFont(font);
        vs->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(vs);

        second_player = new QLabel(centralwidget);
        second_player->setObjectName("second_player");
        sizePolicy1.setHeightForWidth(second_player->sizePolicy().hasHeightForWidth());
        second_player->setSizePolicy(sizePolicy1);
        second_player->setFont(font);
        second_player->setStyleSheet(QString::fromUtf8("color: cyan;"));
        second_player->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(second_player);


        verticalLayout->addLayout(horizontalLayout);

        restart = new QPushButton(centralwidget);
        restart->setObjectName("restart");

        verticalLayout->addWidget(restart);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
        first_player->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\276\320\272 1", nullptr));
        vs->setText(QCoreApplication::translate("MainWindow", "VS", nullptr));
        second_player->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\276\320\272 2", nullptr));
        restart->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
