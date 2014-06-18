#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
private:
    list<ObserverData*> myObservers; //Liste mit allen Observern
    Temperaturen myTemperaturen;
    vector<Temperaturen> myTemperatur;

public:
    Subject();
    void getData();
    void notify();
    void attach(ObserverData* myObserver); //Observer anmelden
    void detach(ObserverData* myObserver); //Observer abmelden
};

#endif // SUBJECT_H
