#include "observerrohform.h"

ObserverRohform::ObserverRohform(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverRohform::update(Data data_myTemperaturdaten)
{

    if(data_myTemperaturdaten.Metadaten.find("Fehler")==std::string::npos)
    {
        string Str_Temperaturdaten;
        vector<Temperaturen>::iterator iter = data_myTemperaturdaten.vectorTemperaturen.begin();
        for(;iter!=data_myTemperaturdaten.vectorTemperaturen.end();iter++)
        {

            Str_Temperaturdaten = Str_Temperaturdaten + (iter)->Ort + ": " + (iter)->str_Temperatur;
            Str_Temperaturdaten = Str_Temperaturdaten +"\n";

        }


        QStr_Temperaturdaten = QString::fromUtf8(Str_Temperaturdaten.c_str());
    }

    else
        QStr_Temperaturdaten = QString::fromUtf8("Fehler beim Laden der Daten");

    myMainWindow->setRohdaten(QStr_Temperaturdaten);




}
