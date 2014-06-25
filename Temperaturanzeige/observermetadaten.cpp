#include "observermetadaten.h"

ObserverMetadaten::ObserverMetadaten(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverMetadaten::update(Data data_myTemperaturdaten)
 {

    if(data_myTemperaturdaten.int_error==0)
       QStr_Metadaten = QString::fromUtf8(data_myTemperaturdaten.Metadaten.c_str());
    if(data_myTemperaturdaten.int_error==404)
        QStr_Metadaten = QString::fromUtf8("Fehler 404, Seite nicht gefunden");
    if(data_myTemperaturdaten.int_error==500)
        QStr_Metadaten = QString::fromUtf8("Fehler: Server nicht gefunden");
    if(data_myTemperaturdaten.int_error==300)
        QStr_Metadaten = QString::fromUtf8("Internetseite fehlerhaft");
    myMainWindow->setMetadaten(QStr_Metadaten);

 }
