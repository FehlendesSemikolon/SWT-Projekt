#include "observerBalkendiagramm.h"

ObserverBalkendiagramm::ObserverBalkendiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initBalkendiagramm();
}

void ObserverBalkendiagramm::update(Data data_myTemperaturdaten)
{
    if(data_myTemperaturdaten.int_error==0)
    {
       QVector<double> x(6), y(6);

        vector<Temperaturen>::iterator iter = data_myTemperaturdaten.vectorTemperaturen.begin();


       int int_i=0;
       for (;iter!=data_myTemperaturdaten.vectorTemperaturen.end();iter++)
       {
            x[int_i] = int_i+1;
            y[int_i]=iter->double_Temperatur;
            int_i++;
       }

        myMainWindow->setBalkendiagramm(x,y);
    }
}
