#ifndef OBSERVERBALKENDIAGRAMM_H
#define OBSERVERBALKENDIAGRAMM_H

#include "mainwindow.h"
#include "observerdata.h"

class ObserverBalkendiagramm : public ObserverData
{

private:
    MainWindow *myMainWindow;

public:
    ObserverBalkendiagramm(MainWindow *w);
    void update(Data data_myTemperaturdaten);

};

#endif // OBSERVERBALKENDIAGRAMM_H
