#ifndef OBERVERBALKENDIAGRAMM_H
#define OBERVERBALKENDIAGRAMM_H

#include "mainwindow.h"
#include "observerdata.h"

/*
Observerklasse für die Datendarstellung des Punktdiagramms
 */
class ObserverPunktdiagramm : public ObserverData
{

private:
    MainWindow *MainWindow_ptrMainWindow; //Verbindung zum Controller

public:
    ObserverPunktdiagramm(MainWindow *MainWindow_Referenz);
    void update(DataContainer DataContainer_Temperaturdaten); //Funktion zur Benachrichtigung

};


#endif // OBERVERBALKENDIAGRAMM_H
