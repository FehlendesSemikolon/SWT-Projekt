#ifndef OBSERVERMETADATEN_H
#define OBSERVERMETADATEN_H
#include "mainwindow.h"
#include "observerdata.h"

class ObserverMetadaten : public ObserverData
{    
private:
    MainWindow *myMainWindow;
    QString QStr_Metadaten;

public:
    ObserverMetadaten(MainWindow *w);
    void update(DataContainer Temperaturdaten);

};

#endif // OBSERVERMETADATEN_H
