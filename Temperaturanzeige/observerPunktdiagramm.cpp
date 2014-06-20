#include "oberverPunktdiagramm.h"


ObserverPunktdiagramm::ObserverPunktdiagramm(MainWindow *w)
{
    myMainWindow = w;
    w->initPunktdiagramm();
}

void ObserverPunktdiagramm::update(Data data_myTemperaturdaten)
{
   QVector<double> x(6), y(6);

    vector<Temperaturen>::iterator iter = data_myTemperaturdaten.vectorTemperaturen.begin();


   int int_i=0;
   for (;iter!=data_myTemperaturdaten.vectorTemperaturen.end();iter++)
   {
        x[int_i] = int_i;
        y[int_i]=iter->double_Temperatur;
        int_i++;
   }



    myMainWindow->setPunktdiagramm(x,y);
}
