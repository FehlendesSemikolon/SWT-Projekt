#ifndef OBSERVERDATA_H
#define OBSERVERDATA_H
#include <string>
#include <vector>
using namespace std;

struct Temperaturen{
    string Ort;
    double double_Temperatur;
    string str_Temperatur;
};


class ObserverData
{
public:
    ObserverData();
    virtual void update(vector<Temperaturen> vectorTempa)=0;
};

#endif // OBSERVERDATA_H
