#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "ui_mainwindow.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void setRohdaten(QString QStr_Temperaturdaten);
     void setMetadaten(QString QStr_Metadaten);
     void setPunktdiagramm(QVector<double> x, QVector<double> y);
     void setBalkendiagramm(QVector<double> x, QVector<double> y);
     void initPunktdiagramm();
     void initBalkendiagramm();

private:
    Ui::MainWindow *ui;
    QCPBars *myBars;

};

#endif // MAINWINDOW_H
