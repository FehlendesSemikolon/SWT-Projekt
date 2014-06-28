#include "observerrohform.h"

ObserverRohform::ObserverRohform(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverRohform::update(DataContainer Temperaturdaten)
{

    if(Temperaturdaten.Metadaten.find("Fehler")==std::string::npos)
    {
        string Str_Temperaturdaten;
        map<string,double>::iterator iter = Temperaturdaten.map_Temperaturen.begin();

        for(;iter != Temperaturdaten.map_Temperaturen.end();iter++)
        {
            Str_Temperaturdaten = Str_Temperaturdaten + (iter)->first + ": " + to_string((iter)->second);
            Str_Temperaturdaten = Str_Temperaturdaten +"\n";

        }


        QStr_Temperaturdaten = QString::fromUtf8(Str_Temperaturdaten.c_str());
    }

    else
        QStr_Temperaturdaten = QString::fromUtf8("Fehler beim Laden der Daten");

    myMainWindow->setRohdaten(QStr_Temperaturdaten);




}
