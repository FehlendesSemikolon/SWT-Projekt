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
    MainWindow *myMainWindow; //Verbindung zum Controller

public:
    ObserverBalkendiagramm(MainWindow *w);
    void update(DataContainer Temperaturdaten); //Funktion zur Benachrichtigung

};

#endif // OBSERVERBALKENDIAGRAMM_H
