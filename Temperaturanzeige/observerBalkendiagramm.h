#ifndef OBSERVERBALKENDIAGRAMM_H
#define OBSERVERBALKENDIAGRAMM_H

#include "mainwindow.h"
#include "observerdata.h"


/*
Observerklasse für die Datendarstellung des Balkendiagramms.
 */
class ObserverBalkendiagramm : public ObserverData
{

private:
    MainWindow *MainWindow_ptrMainWindow; //Verbindung zum Controller

public:
    ObserverBalkendiagramm(MainWindow *MainWindow_Referenz);
    void update(DataContainer DataContainer_Temperaturdaten); //Funktion zur Benachrichtigung

};

#endif // OBSERVERBALKENDIAGRAMM_H
