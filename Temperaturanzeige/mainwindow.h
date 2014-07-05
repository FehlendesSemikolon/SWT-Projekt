#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "ui_mainwindow.h"
#include "subject.h"

#define UPDATEINTERVALL 60000 //1 Minute

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Funktionen zum Ausgaben der Meta und Temperaturen als Zeichenfolge
     void setRohdaten(QString QStr_Temperaturdaten);
     void setMetadaten(QString QStr_Metadaten);

     //Funktionen zum Zeichenen der Diagramme. Erwartet werden die Einzelnen Temperaturen als x/y Kooardiate
     //sowie der jeweils zugehörige Ortsname als QString
     void setPunktdiagramm(QVector<double> x, QVector<double> y, QVector<QString> QString_Labels);
     void setBalkendiagramm(QVector<double> x, QVector<double> y, QVector<QString> QString_Labels);

     //Funktionen zum Initialisieren der einzelenen Diagramme
     void initPunktdiagramm();
     void initBalkendiagramm();

     //Registierung des Subjects um bei einem Timerüberlauf das Subject informiert werden kann neue daten ab zu rufen
     void addSubject(Subject *s);


public slots:

     //Funktion welche beim Timerüberlauf aufgerufen wird
     void TimerOverflow();


private:
    Ui::MainWindow *ui;
    QCPBars *QCPBars_Bars;
    Subject *Subject_updateableSubject;
    QTimer *QTimer_DataUpdateTimer;

};

#endif // MAINWINDOW_H
