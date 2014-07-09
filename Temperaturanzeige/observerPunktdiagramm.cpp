#include "oberverPunktdiagramm.h"


ObserverPunktdiagramm::ObserverPunktdiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initPunktdiagramm();
}

void ObserverPunktdiagramm::update(DataContainer Temperaturdaten)
{
    QVector<double> x(6), y(6); //Stellen die x/y Pärchen im Koordinatensystem dar
    QVector<QString> QString_Labels; //Stellt die Beschriftung eines jeden x/y Pärchens dar
    int i=0;

    if(Temperaturdaten.Metadaten.find("Fehler")==std::string::npos) //Prüfe ob kein Fehler aufgetreten ist
    {

        map<string,double>::iterator iter = Temperaturdaten.map_Temperaturen.begin(); //Erstellen eines Iterators

        for(;iter != Temperaturdaten.map_Temperaturen.end();iter++) //Benötigte Daten aus übergebnem Datencontainer auslesen und
        {                                                           //in die jeweils passende Variable kopieren

            QString_Labels << QString::fromUtf8( (iter->first).c_str()); //Cstring in QString konvertieren
            x[i] = i;
            y[i]=iter->second;
            i++;
       }

        myMainWindow->setPunktdiagramm(x,y,QString_Labels); //Übergabe der fertig vorbereiteten Daten an den Controller zum Zeichnen des Punktdiagramms
    }
}
