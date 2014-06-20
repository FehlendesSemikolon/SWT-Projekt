#ifndef OBERVERBALKENDIAGRAMM_H
#define OBERVERBALKENDIAGRAMM_H
#include "mainwindow.h"
#include "observerdata.h"

class ObserverPunktdiagramm : public ObserverData
{

private:
    MainWindow *myMainWindow;

public:
    ObserverPunktdiagramm(MainWindow *w);
    void update(Data data_myTemperaturdaten);

};


#endif // OBERVERBALKENDIAGRAMM_H
