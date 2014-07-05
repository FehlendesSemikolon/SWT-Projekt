#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>
#include <vector>
#include "observerdata.h"
#include "DataContainer.h"


#define URL_DATA L"http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"

using namespace std;

class Subject
{

private:
    list<ObserverData*> myObservers; //Liste mit allen Observern
    DataContainer *DataContainer_Temperaturdaten;


public:
    Subject();
    void getData();
    string downloadData();
    void parseData(string str_Input);
    void notify();
    void attach(ObserverData* myObserver); //Observer anmelden
    void detach(ObserverData* myObserver); //Observer abmelden

};

#endif // SUBJECT_H
