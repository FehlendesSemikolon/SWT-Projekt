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

struct Data{
    string Metadaten;
    vector<Temperaturen> vectorTemperaturen;
};

class ObserverData
{
public:
    ObserverData();
    virtual void update(Data data_myTemperaturdaten)=0;
};

#endif // OBSERVERDATA_H
