#include "oberverPunktdiagramm.h"


ObserverPunktdiagramm::ObserverPunktdiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initPunktdiagramm();
}

void ObserverPunktdiagramm::update(Data data_myTemperaturdaten)
{
    if(data_myTemperaturdaten.int_error==0)
    {
       QVector<double> x(6), y(6);

        vector<Temperaturen>::iterator iter = data_myTemperaturdaten.vectorTemperaturen.begin();



       for (int i=0;iter!=data_myTemperaturdaten.vectorTemperaturen.end();iter++)
       {
            x[i] = i;
            y[i]=iter->double_Temperatur;
            i++;
       }

        myMainWindow->setPunktdiagramm(x,y);
    }
}
