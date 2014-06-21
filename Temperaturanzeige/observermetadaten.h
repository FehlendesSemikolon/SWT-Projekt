#ifndef OBSERVERMETADATEN_H
#define OBSERVERMETADATEN_H
#include "mainwindow.h"
#include "observerdata.h"

class ObserverMetadaten : public ObserverData
{    
private:
    MainWindow *myMainWindow;

public:
    ObserverMetadaten(MainWindow *w);
    void update(Data data_myTemperaturdaten);

};

#endif // OBSERVERMETADATEN_H