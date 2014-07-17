#include "observermetadaten.h"

ObserverMetadaten::ObserverMetadaten(MainWindow *MainWindow_Referenz)
{
    MainWindow_ptrMainWindow=MainWindow_Referenz;
}

void ObserverMetadaten::update(DataContainer DataContainer_Temperaturdaten)
 { 
    QString_Metadaten = QString::fromUtf8(DataContainer_Temperaturdaten.string_Metadaten.c_str()); //Wandle den Metadaten String in einen QString
    MainWindow_ptrMainWindow->setMetadaten(QString_Metadaten); //Übergebe die Metadaten an den Controller zum Anzeigen auf der Benutzeroberfläche
 }
