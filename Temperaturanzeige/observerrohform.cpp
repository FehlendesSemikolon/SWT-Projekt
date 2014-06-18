#include "observerrohform.h"

ObserverRohform::ObserverRohform(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverRohform::update(Data data_myTemperaturdaten)
{
    string Str_Temperaturdaten;
     vector<Temperaturen>::iterator iter = data_myTemperaturdaten.vectorTemperaturen.begin();
    for(;iter!=data_myTemperaturdaten.vectorTemperaturen.end();iter++)
    {

        Str_Temperaturdaten = Str_Temperaturdaten + (iter)->Ort + ": " + (iter)->str_Temperatur;
        Str_Temperaturdaten = Str_Temperaturdaten +"\n";
    }

    QString QStr_Temperaturdaten = QString::fromUtf8(Str_Temperaturdaten.c_str());
    myMainWindow->setRohdaten(QStr_Temperaturdaten);

}
