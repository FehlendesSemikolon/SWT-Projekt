#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <string>
#include <map>

using namespace std;

/*
Diese Klasse stellt den Container da in welchem die Heruntergeladenen und geparsten
Daten gespeichert werden um sie an weitere Komponenten weitergeben zu können
*/

class DataContainer
{
public:
    DataContainer();

    string Metadaten;
    map<string, double> map_Temperaturen; //Pärchen aus Ort(als String) und der zugehörigen Temperatur(als Double)


};


#endif // DATACONTAINER_H
