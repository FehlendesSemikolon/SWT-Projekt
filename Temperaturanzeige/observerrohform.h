#ifndef OBSERVERROHFORM_H
#define OBSERVERROHFORM_H
#include "mainwindow.h"
#include "observerdata.h"
#include <vector>

/*
Observerklasse für die Datendarstellung der Rohdaten
 */

class ObserverRohform : public ObserverData
{
private:
    MainWindow *MainWindow_ptrMainWindow; //Verbindung zum Controller
    QString QString_Temperaturdaten;

public:
    ObserverRohform(MainWindow *MainWindow_Referenz);
    void update(DataContainer DataContainer_Temperaturdaten); //Funktion zur Benachrichtigung

};

#endif // OBSERVERROHFORM_H
