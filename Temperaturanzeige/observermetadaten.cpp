#include "observermetadaten.h"

ObserverMetadaten::ObserverMetadaten(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverMetadaten::update(DataContainer Temperaturdaten)
 { 
    QStr_Metadaten = QString::fromUtf8(Temperaturdaten.Metadaten.c_str());
    myMainWindow->setMetadaten(QStr_Metadaten);
 }
