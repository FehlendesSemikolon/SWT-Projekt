#ifndef OBSERVERROHFORM_H
#define OBSERVERROHFORM_H
#include "mainwindow.h"
#include "observerdata.h"
#include <vector>

class ObserverRohform : public ObserverData
{
private:
    MainWindow *myMainWindow;

public:
    ObserverRohform(MainWindow *w);
    void update(vector<Temperaturen> vectorTempa);

};

#endif // OBSERVERROHFORM_H
