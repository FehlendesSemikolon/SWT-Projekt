#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>
#include <vector>
#include "observerdata.h"
#include "DataContainer.h"


#define URL_DATA L"http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"
//URL von der die Daten gelesen werden sollen

/*
Diese Klasse informiert die Observerklassen wenn neue Daten zur Verfügung stehen
Die Klasse lädt die Daten aus dem Internet und speichert sie in einem Objekt der Klasse DataContainer
*/

using namespace std;

class Subject
{

private:
    list<ObserverData*> list_Observer; //Liste mit allen Observern
    DataContainer *DataContainer_Temperaturdaten; //Daten Container für die geparsten Daten

    string downloadData(); //Lädt die Daten aus dem Internet und gibt diese als einen String zurück
    void parseData(string string_Input); //Parst die heruntergeladenen Daten, Aufteilung in:
                                         //Metadaten (String)
                                         //Ort (String)
                                         //Temperatur (Double)
                                         //Diese geparsten Daten werden in DataContainer_Temperaturdaten gelegt
    void notify(); //Informiert alle angemeldeten Observer über neue Daten

public:
    Subject();
    void getData(); //ruft die Funktionen donwloadData und parseData auf
                    //Überprüft ob das Herrunterladen der Daten geklappt hat, im Fehlerfall wird der Fehler behandelt
                    //ruft die Funktion notify auf

    void attach(ObserverData* ObserverData_Observer); //Observer anmelden
    void detach(ObserverData* ObserverData_Observer); //Observer abmelden

};

#endif // SUBJECT_H
