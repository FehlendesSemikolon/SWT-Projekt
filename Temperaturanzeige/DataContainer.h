#ifndef DATACONTAINER_H
#define DATACONTAINER_H


//#include <QString>
#include <string>
#include <map>

using namespace std;

class DataContainer
{
public:
    DataContainer();

    string Metadaten;
    map<string, double> map_Temperaturen;



//public:


};


#endif // DATACONTAINER_H
