#include "observermetadaten.h"

ObserverMetadaten::ObserverMetadaten(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverMetadaten::update(DataContainer Temperaturdaten)
 { 
    QStr_Metadaten = QString::fromUtf8(Temperaturdaten.Metadaten.c_str()); //Wandle den Metadaten String in einen QStr
    myMainWindow->setMetadaten(QStr_Metadaten); //Übergebe die Metadaten an den Controller zum Anzeigen auf der Benutzeroberfläche
 }
