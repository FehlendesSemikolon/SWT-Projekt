#include "observerBalkendiagramm.h"

ObserverBalkendiagramm::ObserverBalkendiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initBalkendiagramm();
}

void ObserverBalkendiagramm::update(DataContainer Temperaturdaten)
{
    QVector<double> x(6), y(6);
    int i=0;
    if(Temperaturdaten.Metadaten.find("Fehler")==std::string::npos)
    {

        map<string,double>::iterator iter = Temperaturdaten.map_Temperaturen.begin();

        for(;iter != Temperaturdaten.map_Temperaturen.end();iter++)
        {
            x[i] = i;
            y[i]=iter->second;
            i++;
       }
        myMainWindow->setBalkendiagramm(x,y);
    }

}
