#include "observerrohform.h"



ObserverRohform::ObserverRohform(MainWindow *w)
{
    myMainWindow=w;
}

void ObserverRohform::update(vector<Temperaturen> vectorTempa)
{
    string myString;
    vector<Temperaturen>::iterator iter = vectorTempa.begin();
    for(;iter!=vectorTempa.end();iter++)
    {

        myString = myString + (iter)->Ort + ": " + (iter)->str_Temperatur;
        myString = myString +"\n";
    }

    myMainWindow->mySetText(myString);

}
