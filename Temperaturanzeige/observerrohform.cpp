#include "observerrohform.h"
#include <string>
using namespace std;

ObserverRohform::ObserverRohform(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverRohform::update(DataContainer Temperaturdaten)
{

    if(Temperaturdaten.Metadaten.find("Fehler")==std::string::npos)
    {
        string Str_Temperaturdaten; //String in dem alle Orte und Temperaturen geschrieben werden
        map<string,double>::iterator iter = Temperaturdaten.map_Temperaturen.begin();

        for(;iter != Temperaturdaten.map_Temperaturen.end();iter++)
        {
            char char_Temperaut[20]; //Temperatur als Char
            sprintf_s(char_Temperaut,"%.2f",(iter)->second,20); //Schreibe Temepratur in ein Char Array
     //     Str_Temperaturdaten = Str_Temperaturdaten + (iter)->first + ": " + to_string((iter)->second,);
            Str_Temperaturdaten = Str_Temperaturdaten + (iter)->first + ": " + char_Temperaut; //Schreibe Ort und Temepratur in einen String
            Str_Temperaturdaten = Str_Temperaturdaten +"\n";

        }

        QStr_Temperaturdaten = QString::fromUtf8(Str_Temperaturdaten.c_str()); //Wandle den Temeperaturdaten String in einen QStr
    }

    else
        QStr_Temperaturdaten = QString::fromUtf8("Fehler beim Laden der Daten");

    myMainWindow->setRohdaten(QStr_Temperaturdaten); //Übergebe die Temperaturdaten in Rohform an den Controller zum Anzeigen auf der Benutzeroberfläche




}
