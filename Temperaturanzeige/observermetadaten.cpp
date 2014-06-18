#include "observermetadaten.h"

ObserverMetadaten::ObserverMetadaten(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverMetadaten::update(Data data_myTemperaturdaten)
 {
    QString QStr_Metadaten = QString::fromUtf8(data_myTemperaturdaten.Metadaten.c_str());
    myMainWindow->setMetadaten(QStr_Metadaten);

 }
