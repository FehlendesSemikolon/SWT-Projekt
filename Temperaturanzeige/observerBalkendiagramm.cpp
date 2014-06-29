#include "observerBalkendiagramm.h"

ObserverBalkendiagramm::ObserverBalkendiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initBalkendiagramm();
}

void ObserverBalkendiagramm::update(DataContainer Temperaturdaten)
{
    QVector<double> x(6), y(6);
    QVector<QString> QString_Labels;
    int i=0;

    if(Temperaturdaten.Metadaten.find("Fehler")==std::string::npos)
    {

        map<string,double>::iterator iter = Temperaturdaten.map_Temperaturen.begin();


        QString_Labels << QString::fromUtf8("");
        for(;iter != Temperaturdaten.map_Temperaturen.end();iter++)
        {
            QString_Labels << QString::fromUtf8( (iter->first).c_str());

            x[i] = i+1;
            y[i]=iter->second;
            i++;


       }
        myMainWindow->setBalkendiagramm(x,y,QString_Labels);
    }

}
