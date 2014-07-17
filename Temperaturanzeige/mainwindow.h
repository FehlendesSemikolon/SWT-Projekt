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

/*
Diese Klasse stellt den Controller gemäß des MVC Pattern dar
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Funktionen zum Ausgaben der Meta und Temperaturen als Zeichenfolge
     void setRohdaten(QString QString_Temperaturdaten);
     void setMetadaten(QString QString_Metadaten);

     //Funktionen zum Zeichenen der Diagramme. Erwartet werden die Einzelnen Temperaturen als x/y Kooardiate
     //sowie der jeweils zugehörige Ortsname als QString
     void setPunktdiagramm(QVector<double> x, QVector<double> y, QVector<QString> QString_Labels);
     void setBalkendiagramm(QVector<double> x, QVector<double> y, QVector<QString> QString_Labels);

     //Funktionen zum Initialisieren der einzelenen Diagramme
     void initPunktdiagramm();
     void initBalkendiagramm();

     //Registierung des Subjects um bei einem Timerüberlauf das Subject informiert werden kann neue daten ab zu rufen
     void addSubject(Subject *Subject_ptrSubject);


public slots:

     //Funktion welche beim Timerüberlauf aufgerufen wird
     void TimerOverflow();


private:
    Ui::MainWindow *ui; //Generiert durch IDE
    QCPBars *QCPBars_Bars;//Wird benötigt um ein Balkendiagramm in ein qCoustomPlot-widget zu zeichnen
    Subject *Subject_updateableSubject; //Verweis auf das Subjekt welches die Methode zum aktuallieren der Daten bereit stellt
                                        //um diese zyklisch durch den Timer aufrufen zu können
    QTimer *QTimer_DataUpdateTimer; //Timer zum zyklischen aktuallisieren der Daten

};

#endif // MAINWINDOW_H
