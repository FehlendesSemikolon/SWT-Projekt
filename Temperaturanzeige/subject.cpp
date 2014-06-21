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
    list<ObserverData*>::iterator iter = myObservers.begin();
    for(;iter!=myObservers.end();iter++)
        (*iter)->update(Data_Temperaturdaten);
}


void Subject::getData()
{
    //Quelle: http://www.gutefrage.net/frage/c-online-datei-auslesen
    HANDLE hLib;
    HANDLE hConn;
    string str_Input;


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
        char array[4048]={0};
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
            str_Input=array;


        } while(d!=0);
        InternetCloseHandle(hConn);
    }

    /* Hier kann man noch mehrere URLs öffnen ... */

    /* Nach dem Lesen der letzten Webseite */

    InternetCloseHandle(hLib);
    // Quelle Ende

    int int_i=0;
    int int_countData=0;
    int int_countMetadata=0;

    char * buffer = new char[str_Input.length()];
    strcpy(buffer,str_Input.c_str());



    while(buffer[int_i]!=NULL) //ermittle Anzahl der Zeilen
    {

        if (buffer[int_i]=='\n')
            int_countData++;  //Anzahl der Zeilen mit Temperaturdaten
        if (buffer[int_i]=='#')
            int_countMetadata++; //Anzahl der Zeilen mit Metadatem
        int_i++;
    }

    Data_Temperaturdaten.Metadaten.clear();
    for(int k=0;k<int_countMetadata;k++) //Speichere Metadaten in Vektor und lösche die Zeilen mit den Metadaten aus dem Input String
    {
        size_t size_t_posNewline;
        size_t size_t_posColon;
        size_t_posColon=str_Input.find(":");
        size_t_posNewline=str_Input.find("\n");
        Data_Temperaturdaten.Metadaten=Data_Temperaturdaten.Metadaten + str_Input.substr(size_t_posColon+1,size_t_posNewline-size_t_posColon);
        str_Input=str_Input.substr(size_t_posNewline+1,str_Input.length());
    }

    Data_Temperaturdaten.vectorTemperaturen.clear();
    for (int i=0;i<(int_countData-int_countMetadata);i++) //Vektor mit allen Orten und Temperaturen erstellen/befüllen
    {
        size_t size_t_posOrt;
        size_t size_t_posTemperatur;

        size_t_posOrt=str_Input.find(",");
        size_t_posTemperatur=str_Input.find("\n");



        Data_Temperaturdaten.vectorTemperaturen.push_back(Temperaturen());
        Data_Temperaturdaten.vectorTemperaturen[i].Ort=str_Input.substr(0,size_t_posOrt);
        Data_Temperaturdaten.vectorTemperaturen[i].str_Temperatur=str_Input.substr(size_t_posOrt+1,size_t_posTemperatur-size_t_posOrt-1);
        Data_Temperaturdaten.vectorTemperaturen[i].double_Temperatur=atof(Data_Temperaturdaten.vectorTemperaturen[i].str_Temperatur.c_str());

        str_Input=str_Input.substr(size_t_posTemperatur+1,str_Input.length());
    }


    notify();

}


