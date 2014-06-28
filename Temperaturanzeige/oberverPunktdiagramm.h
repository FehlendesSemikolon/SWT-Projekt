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
    void update(DataContainer Temperaturdaten);

};


#endif // OBERVERBALKENDIAGRAMM_H
