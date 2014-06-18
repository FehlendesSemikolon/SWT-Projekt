#include "subject.h"


#include <iostream>
#include <windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
//#pragma comment(lib, "version.lib")



Subject::Subject()
{
}

void Subject::attach(ObserverData* myObserver)
{
    myObservers.push_back(myObserver);
}

void Subject::detach(ObserverData* myObserver)
{
    myObservers.remove(myObserver);
}

void Subject::notify()
{

}


void Subject::getData()
{
    //Quelle: http://www.gutefrage.net/frage/c-online-datei-auslesen
    HANDLE hLib;
    HANDLE hConn;
    string myInput;


    hLib=InternetOpen(L"MeinProgramm",
        INTERNET_OPEN_TYPE_PRECONFIG,
        NULL,NULL,0);
    hConn=InternetOpenUrl(hLib,
        L"http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt",
        NULL,0,0,0);
    if(hConn==NULL)
    {
        /* ERROR */
    }
    else
    {
        char array[4048];
        DWORD d;
        do {
            d=0;
            InternetReadFile(hConn,array,4048,&d);
            /* d=0 = Ende der Webseite erreicht
             * d=n = array[0...(n-1)] enthält n Bytes von Webseite
             * Tipp: Mit InternetReadFile(hconn,&c,1,&d);
             * kann man ein einzelnes Zeichen in die "BYTE"-Variable
             * "c" einlesen! */

             /* Daten verarbeiten */
            myInput=array;


        } while(d!=0);
        InternetCloseHandle(hConn);
    }

    /* Hier kann man noch mehrere URLs öffnen ... */

    /* Nach dem Lesen der letzten Webseite */

    InternetCloseHandle(hLib);
    // Quelle Ende

    int i=0;
    int countData=0;
    int countMeta=0;

    char * buffer = new char[myInput.length()];
    strcpy(buffer,myInput.c_str());


    while(buffer[i]!=NULL) //ermittle Anzahl der Zeilen
    {

        if (buffer[i]=='\n')
            countData++;  //Anzahl der Zeilen mit Temperaturdaten
        if (buffer[i]=='#')
            countMeta++; //Anzahl der Zeilen mit Metadatem
        i++;
    }

    for(int k=0;k<countMeta;k++) //lösche die Zeilen mit den Metadaten
    {
        size_t pos;
        pos=myInput.find("\n");
        myInput=myInput.substr(pos+1,myInput.length());
    }

    for (int i=0;i<(countData-countMeta);i++) //Vektor mit allen Orten und Temperaturen erstellen/befüllen
    {
        size_t posOrt;
        size_t posTemperatur;
        double double_tempDaten;
        string tempDaten;

        posOrt=myInput.find(",");
        posTemperatur=myInput.find("\n");
        myTemperatur.push_back(Temperaturen());
        myTemperatur[i].Ort=myInput.substr(0,posOrt);
        myTemperatur[i].str_Temperatur=myInput.substr(posOrt+1,posTemperatur-posOrt-1);

        tempDaten=myInput.substr(posOrt,posTemperatur-posOrt-1);
        double_tempDaten=atof(tempDaten.c_str());

        myInput=myInput.substr(posTemperatur+1,myInput.length());
    }


    notify();

}


