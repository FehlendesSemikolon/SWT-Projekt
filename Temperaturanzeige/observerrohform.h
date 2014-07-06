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
    MainWindow *myMainWindow; //Verbindung zum Controller
    QString QStr_Temperaturdaten;

public:
    ObserverRohform(MainWindow *w);
    void update(DataContainer Temperaturdaten); //Funktion zur Benachrichtigung

};

#endif // OBSERVERROHFORM_H
