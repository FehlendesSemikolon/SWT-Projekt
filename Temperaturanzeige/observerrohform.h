#ifndef OBSERVERROHFORM_H
#define OBSERVERROHFORM_H
#include "mainwindow.h"
#include "observerdata.h"
#include <vector>

class ObserverRohform : public ObserverData
{
private:
    MainWindow *myMainWindow;
    QString QStr_Temperaturdaten;

public:
    ObserverRohform(MainWindow *w);
    void update(DataContainer Temperaturdaten);

};

#endif // OBSERVERROHFORM_H
