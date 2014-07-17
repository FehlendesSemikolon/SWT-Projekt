#ifndef OBSERVERDATA_H
#define OBSERVERDATA_H
#include <string>
#include <vector>
#include "DataContainer.h"

using namespace std;

/*
Interfaceklasse für die Observer
*/
class ObserverData
{
public:
    ObserverData();
    virtual void update(DataContainer DataContainer_Temperaturdaten)=0; //Abstrakte Funktion zur Benachrichtigung, muss von allen Observern implementiert werden
};

#endif // OBSERVERDATA_H
