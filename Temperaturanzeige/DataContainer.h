#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <string>
#include <map>

using namespace std;

/*
Diese Klasse stellt den Container dar in welchem die Heruntergeladenen und geparsten
Daten gespeichert werden um sie an die Observer weitergeben zu können
*/

class DataContainer
{
public:
    DataContainer();

    string string_Metadaten;
    map<string, double> map_Temperaturen; //Pärchen aus Ort(als String) und der zugehörigen Temperatur(als Double)


};


#endif // DATACONTAINER_H
