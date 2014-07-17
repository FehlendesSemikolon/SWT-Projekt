#ifndef OBSERVERMETADATEN_H
#define OBSERVERMETADATEN_H
#include "mainwindow.h"
#include "observerdata.h"

/*
Observerklasse für die Datendarstellung der Metadaten
 */

class ObserverMetadaten : public ObserverData
{    
private:
    MainWindow *MainWindow_ptrMainWindow; //Verbindung zum Controller
    QString QString_Metadaten;

public:
    ObserverMetadaten(MainWindow *MainWindow_Referenz);
    void update(DataContainer DataContainer_Temperaturdaten);//Funktion zur Benachrichtigung

};

#endif // OBSERVERMETADATEN_H
