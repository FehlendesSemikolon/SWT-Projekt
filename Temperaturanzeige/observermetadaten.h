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
    MainWindow *myMainWindow; //Verbindung zum Controller
    QString QStr_Metadaten;

public:
    ObserverMetadaten(MainWindow *w);
    void update(DataContainer Temperaturdaten);//Funktion zur Benachrichtigung

};

#endif // OBSERVERMETADATEN_H
