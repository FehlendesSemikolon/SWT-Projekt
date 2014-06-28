#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>
#include <qtimer.h>
#include <vector>
#include "observerdata.h"
#include "observerrohform.h"
#include "DataContainer.h"

using namespace std;

class Subject
{
private:
    list<ObserverData*> myObservers; //Liste mit allen Observern

   // Temperaturen myTemperaturen;
   // vector<Temperaturen> myTemperatur;

    //Data Data_Temperaturdaten;
    DataContainer *DataContainer_Temperaturdaten;


public:
    Subject();
    void getData();
    void notify();
    void attach(ObserverData* myObserver); //Observer anmelden
    void detach(ObserverData* myObserver); //Observer abmelden


};

#endif // SUBJECT_H
