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
    myObservers.push_back(myObserver); //melde den Observer beim Subject an
}

void Subject::detach(ObserverData* myObserver)
{
    myObservers.remove(myObserver); //melde den Observer beim Subject ab
}

void Subject::notify()
{
    list<ObserverData*>::iterator iter = myObservers.begin();
    for(;iter!=myObservers.end();iter++)                 //Gehe die Liste der angemdeleten Observer durch
        (*iter)->update(*DataContainer_Temperaturdaten); //Informiere den Observer über neue Daten

}


string Subject::downloadData()
{
    HANDLE handle_InternetConnection; //Handle für die Internetverbindung
    HANDLE handle_URL;                //Handle für die URL
    char char_readData[4048] = { 0 }; //Array für die eingelesene Daten


    handle_InternetConnection = InternetOpen(L"MeinProgramm", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); //Stelle Internetverbindung her
    handle_URL = InternetOpenUrl(handle_InternetConnection, URL_DATA, NULL, 0, 0, 0); //Öffne die URL URL_DATA

    if (handle_URL != NULL) //Öffnen der URL erfolgreich
    {
        DWORD DWORD_NumberOfBytesRead; //Anzahl der bereits eingelesenen Bytes, wird von InternetReadFile zu beginn auf 0 gesetzt
        InternetReadFile(handle_URL, char_readData, 4048, &DWORD_NumberOfBytesRead); //lesen Daten aus dem Internet und schreibe diese in char_readData

        InternetCloseHandle(handle_URL);
        InternetCloseHandle(handle_InternetConnection);
        return char_readData;
     }
    else //Fehlerbehandlung
    {
        return "@"; //@ ist der Rückgabewert falls ein Fehler aufgetreten ist (z.B. Server ist nicht erreichbar)
    }
}


void Subject::parseData(string str_Input)
{
    int int_countData=0;     //Anzahl aller Zeilen
    int int_countMetadata=0; //Anzahl der Zeilen mit #
    size_t size_t_len;       //länge des eingelesenen Strings von der Website

    char * char_buffer = new char[str_Input.length()+1];    //buffer für die Input String
    size_t_len=str_Input.length();                 //ermittle die Länge des Input Strings
    strcpy_s(char_buffer,size_t_len+1,str_Input.c_str()); //lege den Input String in den Buffer

    for(int i=0;char_buffer[i]!=NULL;i++) //ermittle Anzahl der Zeilen
    {
        if (char_buffer[i]=='\n')
            int_countData++;  //Anzahl der Zeilen mit Temperaturdaten
        if (char_buffer[i]=='#')
            int_countMetadata++; //Anzahl der Zeilen mit Metadatem
    }


    DataContainer_Temperaturdaten->Metadaten.clear(); //lösche alle alten Metadaten aus dem Container

    for(int i=0;i<int_countMetadata;i++) //Speichere Metadaten in DataContainer und "lösche" die Zeilen mit den Metadaten aus dem Input String
    {
        size_t size_t_posNewline;//Position des Zeichens "\n"
        size_t size_t_posColon;  //Position des Zeichens ":"
        size_t_posColon=str_Input.find(":");
        size_t_posNewline=str_Input.find("\n");
        DataContainer_Temperaturdaten->Metadaten = DataContainer_Temperaturdaten->Metadaten + str_Input.substr(size_t_posColon+1,size_t_posNewline-size_t_posColon); //Füge die Zeile mit den Metadaten dem Container hinzu
        str_Input=str_Input.substr(size_t_posNewline+1,str_Input.length()); //"löscht" die hinzugefügte Zeile aus dem Input String
    }

    DataContainer_Temperaturdaten->map_Temperaturen.clear();
    for (int i=0;i<(int_countData-int_countMetadata);i++) //Container mit allen Orten und Temperaturen befüllen
    {
        size_t size_t_posOrt;       //Poistion des ersten Zeichens nach dem Ort
        size_t size_t_posTemperatur;//Position des ersten Zeichens nach der Temperatur
        string str_Ort;
        double double_tmp;  //Temperaturwert

        size_t_posOrt=str_Input.find(",");
        size_t_posTemperatur=str_Input.find("\n");

        str_Ort =str_Input.substr(0,size_t_posOrt); // to_string(i);    ;//str_Input.substr(0,size_t_posOrt);
        double_tmp = atof( (str_Input.substr(size_t_posOrt+1,size_t_posTemperatur-size_t_posOrt-1)).c_str() ) ;

        DataContainer_Temperaturdaten->map_Temperaturen[str_Ort] = double_tmp; //Lege Ort und Temperatur in den Daten Container

        str_Input=str_Input.substr(size_t_posTemperatur+1,str_Input.length()); //"lösche" die verarbeiteten Daten aus dem Input String
    }

}

void Subject::getData()
{
    string str_Input;           //String für die eingelesenen Daten aus dem Internet
    str_Input = downloadData(); //Lade die Daten von der Website und lege sie in str_Input

    if(str_Input.at(0) == '@')//Fehlerbehandlung
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
            parseData(str_Input); //Wenn keine Fehler aufgetreten sind, parse Daten
        }
    }
    notify(); //Informiere Observer über neue Daten
              //Normalfall: Observer erhalten neue Temperaturdaten
              //Fehlerfall: Observer erhalten Fehlermeldung
}


