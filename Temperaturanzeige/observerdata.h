#ifndef OBSERVERDATA_H
#define OBSERVERDATA_H
#include <string>
#include <vector>
#include "DataContainer.h"

using namespace std;


class ObserverData
{
public:
    ObserverData();
    virtual void update(DataContainer Temperaturdaten)=0;
};

#endif // OBSERVERDATA_H
