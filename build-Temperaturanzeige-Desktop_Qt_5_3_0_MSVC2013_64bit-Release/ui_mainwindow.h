/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_Rohdaten;
    QLabel *label_Metadaten;
    QCustomPlot *widget_Punktdiagramm;
    QCustomPlot *widget_Balkendiagramm;
    QLabel *label_Ueberschrift;
    QLabel *label_Gruppe;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1295, 723);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_Rohdaten = new QLabel(centralWidget);
        label_Rohdaten->setObjectName(QStringLiteral("label_Rohdaten"));
        label_Rohdaten->setGeometry(QRect(910, 10, 201, 131));
        QFont font;
        font.setPointSize(10);
        label_Rohdaten->setFont(font);
        label_Metadaten = new QLabel(centralWidget);
        label_Metadaten->setObjectName(QStringLiteral("label_Metadaten"));
        label_Metadaten->setGeometry(QRect(610, 50, 221, 51));
        QFont font1;
        font1.setPointSize(11);
        label_Metadaten->setFont(font1);
        widget_Punktdiagramm = new QCustomPlot(centralWidget);
        widget_Punktdiagramm->setObjectName(QStringLiteral("widget_Punktdiagramm"));
        widget_Punktdiagramm->setGeometry(QRect(10, 150, 561, 511));
        widget_Balkendiagramm = new QCustomPlot(centralWidget);
        widget_Balkendiagramm->setObjectName(QStringLiteral("widget_Balkendiagramm"));
        widget_Balkendiagramm->setGeometry(QRect(590, 150, 671, 511));
        label_Ueberschrift = new QLabel(centralWidget);
        label_Ueberschrift->setObjectName(QStringLiteral("label_Ueberschrift"));
        label_Ueberschrift->setGeometry(QRect(20, 10, 271, 31));
        QFont font2;
        font2.setPointSize(14);
        label_Ueberschrift->setFont(font2);
        label_Gruppe = new QLabel(centralWidget);
        label_Gruppe->setObjectName(QStringLiteral("label_Gruppe"));
        label_Gruppe->setGeometry(QRect(20, 50, 221, 16));
        QFont font3;
        font3.setPointSize(9);
        label_Gruppe->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1295, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_Rohdaten->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_Metadaten->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_Ueberschrift->setText(QApplication::translate("MainWindow", "Projektarbeit in Softwaretechnik ", 0));
        label_Gruppe->setText(QApplication::translate("MainWindow", "Gruppe 3: Christoph Gnoth, Janik Heller", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
