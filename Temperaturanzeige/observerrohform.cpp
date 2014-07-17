#include "observerrohform.h"
#include <string>
using namespace std;

ObserverRohform::ObserverRohform(MainWindow *MainWindow_Referenz)
{
    MainWindow_ptrMainWindow=MainWindow_Referenz;
}

void ObserverRohform::update(DataContainer DataContainer_Temperaturdaten)
{

    if(DataContainer_Temperaturdaten.string_Metadaten.find("Fehler")==std::string::npos) //Prüfe ob kein Fehler aufgetreten ist
    {
        string string_Temperaturdaten; //String in dem alle Orte und Temperaturen geschrieben werden
        map<string,double>::iterator iter = DataContainer_Temperaturdaten.map_Temperaturen.begin();

        for(;iter != DataContainer_Temperaturdaten.map_Temperaturen.end();iter++)
        {
            char char_Temperaut[20]; //Temperatur als Char
            sprintf_s(char_Temperaut,"%.2f",(iter)->second,20); //Schreibe Temepratur in ein Char Array
            string_Temperaturdaten = string_Temperaturdaten + (iter)->first + ": " + char_Temperaut; //Schreibe Ort und Temepratur in einen String
            string_Temperaturdaten = string_Temperaturdaten +"\n";

        }

        QString_Temperaturdaten = QString::fromUtf8(string_Temperaturdaten.c_str()); //Wandle den Temeperaturdaten String in einen QString
    }

    else //Fehlerbehandlung
    {
        QString_Temperaturdaten = QString::fromUtf8("Fehler beim Laden der Daten");
    }

    MainWindow_ptrMainWindow->setRohdaten(QString_Temperaturdaten); //Übergebe die Rohdaten an den Controller zum Anzeigen auf der Benutzeroberfläche

}
