#include "observerBalkendiagramm.h"

ObserverBalkendiagramm::ObserverBalkendiagramm(MainWindow *MainWindow_Referenz)
{
    MainWindow_ptrMainWindow = MainWindow_Referenz;
    MainWindow_Referenz->initBalkendiagramm();
}

void ObserverBalkendiagramm::update(DataContainer DataContainer_Temperaturdaten)
{
    QVector<double> QVector_xKoordinate(6), QVector_yKoordinate(6); //Stellen die x/y Pärchen im Koordinatensystem dar
    QVector<QString> QString_Labels; //Stellt die Beschriftung eines jeden x/y Pärchens dar
    int int_i=0;

    if(DataContainer_Temperaturdaten.string_Metadaten.find("Fehler")==std::string::npos)  //Prüfe ob kein Fehler aufgetreten ist
    {
        map<string,double>::iterator iter = DataContainer_Temperaturdaten.map_Temperaturen.begin(); //Erstellen eines Iterators

        QString_Labels << QString::fromUtf8(""); //Leersrring einfügen da alle Baalken um eine Stellle verschoben werden
        for(;iter != DataContainer_Temperaturdaten.map_Temperaturen.end();iter++) //Benötigte Daten aus übergebnem Datencontainer auslesen und
        {                                                                         //in die jeweils passende Variable kopieren
            QString_Labels << QString::fromUtf8( (iter->first).c_str());//Cstring in QString konvertieren

            QVector_xKoordinate[int_i] = int_i+1;
            QVector_yKoordinate[int_i]=iter->second;
            int_i++;
       }
       MainWindow_ptrMainWindow->setBalkendiagramm(QVector_xKoordinate,QVector_yKoordinate,QString_Labels); //Übergabe der fertig vorbereiteten Daten an den Controller zum Zeichnen des Punktdiagramms
    }

}
