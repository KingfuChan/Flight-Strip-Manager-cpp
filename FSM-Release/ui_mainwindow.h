/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <lineedit.h>
#include <listwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStay_on_top;
    QAction *actionStatistics;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionOpac_Incr;
    QAction *actionOpac_Decr;
    QAction *actionOpac_Rest;
    QAction *actionReset;
    QAction *actionOpac_Curr;
    QWidget *centralwidget;
    QPushButton *btn_add;
    QPushButton *btn_reset;
    CustomListWidget *list_pend;
    CustomListWidget *list_push;
    CustomListWidget *list_dept;
    CustomLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuSet_opacity;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(648, 662);
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionStay_on_top = new QAction(MainWindow);
        actionStay_on_top->setObjectName(QString::fromUtf8("actionStay_on_top"));
        actionStay_on_top->setCheckable(true);
        actionStatistics = new QAction(MainWindow);
        actionStatistics->setObjectName(QString::fromUtf8("actionStatistics"));
        actionStatistics->setEnabled(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpac_Incr = new QAction(MainWindow);
        actionOpac_Incr->setObjectName(QString::fromUtf8("actionOpac_Incr"));
        actionOpac_Decr = new QAction(MainWindow);
        actionOpac_Decr->setObjectName(QString::fromUtf8("actionOpac_Decr"));
        actionOpac_Rest = new QAction(MainWindow);
        actionOpac_Rest->setObjectName(QString::fromUtf8("actionOpac_Rest"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionOpac_Curr = new QAction(MainWindow);
        actionOpac_Curr->setObjectName(QString::fromUtf8("actionOpac_Curr"));
        actionOpac_Curr->setEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(130, 10, 111, 31));
        QFont font1;
        font1.setPointSize(10);
        btn_add->setFont(font1);
        btn_reset = new QPushButton(centralwidget);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));
        btn_reset->setGeometry(QRect(250, 10, 111, 31));
        btn_reset->setFont(font1);
        list_pend = new CustomListWidget(centralwidget);
        list_pend->setObjectName(QString::fromUtf8("list_pend"));
        list_pend->setGeometry(QRect(10, 50, 111, 421));
        list_pend->setFont(font);
        list_pend->setContextMenuPolicy(Qt::CustomContextMenu);
        list_pend->setDragEnabled(true);
        list_pend->setDragDropOverwriteMode(false);
        list_pend->setDragDropMode(QAbstractItemView::DragDrop);
        list_pend->setDefaultDropAction(Qt::MoveAction);
        list_push = new CustomListWidget(centralwidget);
        list_push->setObjectName(QString::fromUtf8("list_push"));
        list_push->setGeometry(QRect(130, 50, 111, 421));
        list_push->setFont(font);
        list_push->setContextMenuPolicy(Qt::CustomContextMenu);
        list_push->setDragEnabled(true);
        list_push->setDragDropOverwriteMode(false);
        list_push->setDragDropMode(QAbstractItemView::DragDrop);
        list_push->setDefaultDropAction(Qt::MoveAction);
        list_dept = new CustomListWidget(centralwidget);
        list_dept->setObjectName(QString::fromUtf8("list_dept"));
        list_dept->setGeometry(QRect(250, 50, 111, 421));
        list_dept->setFont(font);
        list_dept->setContextMenuPolicy(Qt::CustomContextMenu);
        list_dept->setDragEnabled(true);
        list_dept->setDragDropOverwriteMode(false);
        list_dept->setDragDropMode(QAbstractItemView::DragDrop);
        list_dept->setDefaultDropAction(Qt::MoveAction);
        lineEdit = new CustomLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 111, 31));
        lineEdit->setFont(font1);
        lineEdit->setMaxLength(10);
        lineEdit->setClearButtonEnabled(true);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 648, 26));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuSet_opacity = new QMenu(menuSettings);
        menuSet_opacity->setObjectName(QString::fromUtf8("menuSet_opacity"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(lineEdit, btn_add);
        QWidget::setTabOrder(btn_add, list_pend);
        QWidget::setTabOrder(list_pend, list_push);
        QWidget::setTabOrder(list_push, list_dept);
        QWidget::setTabOrder(list_dept, btn_reset);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addAction(menuSet_opacity->menuAction());
        menuSettings->addAction(actionStay_on_top);
        menuSettings->addSeparator();
        menuSettings->addAction(actionStatistics);
        menuSettings->addAction(actionAbout);
        menuSettings->addSeparator();
        menuSettings->addAction(actionReset);
        menuSettings->addAction(actionExit);
        menuSet_opacity->addAction(actionOpac_Curr);
        menuSet_opacity->addSeparator();
        menuSet_opacity->addAction(actionOpac_Incr);
        menuSet_opacity->addAction(actionOpac_Decr);
        menuSet_opacity->addAction(actionOpac_Rest);

        retranslateUi(MainWindow);
        QObject::connect(btn_add, SIGNAL(clicked()), MainWindow, SLOT(addFlight()));
        QObject::connect(btn_reset, SIGNAL(clicked()), MainWindow, SLOT(resetLists()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), btn_add, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Flight Strip Manager", nullptr));
        actionStay_on_top->setText(QCoreApplication::translate("MainWindow", "Stay on top", nullptr));
#if QT_CONFIG(shortcut)
        actionStay_on_top->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStatistics->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionOpac_Incr->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
#if QT_CONFIG(shortcut)
        actionOpac_Incr->setShortcut(QCoreApplication::translate("MainWindow", "Alt+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpac_Decr->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
#if QT_CONFIG(shortcut)
        actionOpac_Decr->setShortcut(QCoreApplication::translate("MainWindow", "Alt+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpac_Rest->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
#if QT_CONFIG(shortcut)
        actionOpac_Rest->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset lists", nullptr));
        actionOpac_Curr->setText(QCoreApplication::translate("MainWindow", "Current: 100%", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        btn_reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Callsign", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuSet_opacity->setTitle(QCoreApplication::translate("MainWindow", "Set opacity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
