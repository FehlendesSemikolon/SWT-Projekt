#include "subject.h"


#include <iostream>
#include <windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")


Subject::Subject()
{
    DataContainer_Temperaturdaten = new DataContainer();
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
        (*iter)->update(*DataContainer_Temperaturdaten);

}


string Subject::downloadData()
{
    HANDLE hLib;
    HANDLE hConn;
    char array[4048] = { 0 };


    hLib = InternetOpen(L"MeinProgramm", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    hConn = InternetOpenUrl(hLib, URL_DATA, NULL, 0, 0, 0);

    if (hConn != NULL)
    {
        DWORD d;
        InternetReadFile(hConn, array, 4048, &d);

        InternetCloseHandle(hConn);
        InternetCloseHandle(hLib);
        return array;
     }
    else
    {
        return "@"; //@ ist der Rückgabewert falls ein Fehler aufgetreten ist (z.B. Server ist nicht erreichbar)
    }
}


void Subject::parseData(string str_Input)
{
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

    DataContainer_Temperaturdaten->Metadaten.clear();

    for(int k=0;k<int_countMetadata;k++) //Speichere Metadaten in Vektor und lösche die Zeilen mit den Metadaten aus dem Input String
    {
        size_t size_t_posNewline;
        size_t size_t_posColon;
        size_t_posColon=str_Input.find(":");
        size_t_posNewline=str_Input.find("\n");
        DataContainer_Temperaturdaten->Metadaten = DataContainer_Temperaturdaten->Metadaten + str_Input.substr(size_t_posColon+1,size_t_posNewline-size_t_posColon);
        str_Input=str_Input.substr(size_t_posNewline+1,str_Input.length());
    }

    DataContainer_Temperaturdaten->map_Temperaturen.clear();
    for (int i=0;i<(int_countData-int_countMetadata);i++) //Vektor mit allen Orten und Temperaturen erstellen/befüllen
    {
        size_t size_t_posOrt;
        size_t size_t_posTemperatur;
        string str_tmp;
        double double_tmp;

        size_t_posOrt=str_Input.find(",");
        size_t_posTemperatur=str_Input.find("\n");

        str_tmp =str_Input.substr(0,size_t_posOrt); // to_string(i);    ;//str_Input.substr(0,size_t_posOrt);
        double_tmp = atof( (str_Input.substr(size_t_posOrt+1,size_t_posTemperatur-size_t_posOrt-1)).c_str() ) ;

        DataContainer_Temperaturdaten->map_Temperaturen[str_tmp] = double_tmp;


        str_Input=str_Input.substr(size_t_posTemperatur+1,str_Input.length());
    }

}

void Subject::getData()
{
    string str_Input;


    str_Input = downloadData();

    if(str_Input.at(0) == '@')
    {
        DataContainer_Temperaturdaten->Metadaten="Fehler: Server nicht gefunden";
    }
    else
    {
        if(str_Input.find("404 Not")!=std::string::npos)//Fehlerbehandlung wenn Internetseite nicht gefunden
            DataContainer_Temperaturdaten->Metadaten="Fehler 404, Seite nicht gefunden";

        else if(str_Input.find("Friedberger Wetterdienst")==std::string::npos )//Fehlerbehandlung bei fehlerhafter Internetseite
            DataContainer_Temperaturdaten->Metadaten="Fehler: Internetseite fehlerhaft";
        else
        {
            parseData(str_Input);
        }
    }
    notify();


}


