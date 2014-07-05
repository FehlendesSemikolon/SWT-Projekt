#ifndef OBERVERBALKENDIAGRAMM_H
#define OBERVERBALKENDIAGRAMM_H

#include "mainwindow.h"
#include "observerdata.h"

/*
Diese Klasse stellt den Observer für die Datendarstellung als Punktdiagramm dar.
 */
class ObserverPunktdiagramm : public ObserverData
{

private:
    MainWindow *myMainWindow; //Verbindung zum Controller

public:
    ObserverPunktdiagramm(MainWindow *w);
    void update(DataContainer Temperaturdaten); //Funktion zur Benachrichtigung

};


#endif // OBERVERBALKENDIAGRAMM_H
