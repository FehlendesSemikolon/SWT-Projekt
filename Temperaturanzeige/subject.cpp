#include "subject.h"


#include <iostream>
#include <windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")


Subject::Subject()
{
    DataContainer_Temperaturdaten = new DataContainer();
}

void Subject::attach(ObserverData* ObserverData_Observer)
{
    list_Observer.push_back(ObserverData_Observer); //melde den Observer beim Subject an
}

void Subject::detach(ObserverData* ObserverData_Observer)
{
    list_Observer.remove(ObserverData_Observer); //melde den Observer beim Subject ab
}

void Subject::notify()
{
    list<ObserverData*>::iterator iter = list_Observer.begin();
    for(;iter!=list_Observer.end();iter++)                 //Gehe die Liste der angemdeleten Observer durch
        (*iter)->update(*DataContainer_Temperaturdaten); //Informiere den Observer über neue Daten

}


string Subject::downloadData()
{
    HANDLE handle_InternetConnection; //Handle für die Internetverbindung
    HANDLE handle_URL;                //Handle für die URL
    char char_readData[4048] = { 0 }; //Array für die eingelesene Daten


    handle_InternetConnection = InternetOpen(L"MeinProgramm", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); //Stelle Internetverbindung her
    handle_URL = InternetOpenUrl(handle_InternetConnection, URL_DATA, NULL, 0, 0, 0); //Öffne die URL URL_DATA

    if (handle_URL != NULL) //Wenn öffnen der URL erfolgreich
    {
        DWORD DWORD_NumberOfBytesRead; //Anzahl der bereits eingelesenen Bytes, wird von InternetReadFile zu beginn auf 0 gesetzt
        InternetReadFile(handle_URL, char_readData, 4048, &DWORD_NumberOfBytesRead); //lesen Daten aus dem Internet und schreibe diese in char_readData

        InternetCloseHandle(handle_URL);
        InternetCloseHandle(handle_InternetConnection);
        return char_readData;
     }
    else //Fehlerbehandlung
    {
        return ""; //Leerstring ist der Rückgabewert falls ein Fehler aufgetreten ist (z.B. Server ist nicht erreichbar, Leere Website)
    }
}


void Subject::parseData(string string_Input)
{
    int int_countData=0;     //Anzahl aller Zeilen
    int int_countMetadata=0; //Anzahl der Zeilen mit #
    size_t size_t_len;       //länge des eingelesenen Strings von der Website

    size_t_len=string_Input.length();  //ermittle die Länge des Input Strings
    char * char_buffer = new char[size_t_len+1];    //buffer für die Input String
    strcpy_s(char_buffer,size_t_len+1,string_Input.c_str()); //lege den Input String in den Buffer

    for(int int_i=0;char_buffer[int_i]!=NULL;int_i++) //ermittle Anzahl der Zeilen
    {
        if (char_buffer[int_i]=='\n')
            int_countData++;  //Anzahl der Zeilen mit Temperaturdaten
        if (char_buffer[int_i]=='#')
            int_countMetadata++; //Anzahl der Zeilen mit Metadatem
    }


    DataContainer_Temperaturdaten->string_Metadaten.clear(); //lösche alle alten Metadaten aus dem Container

    for(int int_i=0;(int_i<int_countMetadata) && (int_i <6);int_i++) //Speichere Metadaten in DataContainer und "lösche" die Zeilen mit den Metadaten aus dem Input String
                                                                     //liest maximal 6 Datensätze ein
    {
        size_t size_t_posNewline;//Position des Zeichens "\n"
        size_t size_t_posColon;  //Position des Zeichens ":"
        size_t_posColon=string_Input.find(":");
        size_t_posNewline=string_Input.find("\n");
        DataContainer_Temperaturdaten->string_Metadaten = DataContainer_Temperaturdaten->string_Metadaten + string_Input.substr(size_t_posColon+1,size_t_posNewline-size_t_posColon); //Füge die Zeile mit den Metadaten dem Container hinzu
        string_Input=string_Input.substr(size_t_posNewline+1,string_Input.length()); //"löscht" die hinzugefügte Zeile aus dem Input String
    }

    DataContainer_Temperaturdaten->map_Temperaturen.clear();
    for (int int_i=0;int_i<(int_countData-int_countMetadata);int_i++) //Container mit allen Orten und Temperaturen befüllen
    {
        size_t size_t_posOrt;       //Poistion des ersten Zeichens nach dem Ort
        size_t size_t_posTemperatur;//Position des ersten Zeichens nach der Temperatur
        string string_Ort;
        double double_Temperatur;  //Temperaturwert

        size_t_posOrt=string_Input.find(",");
        size_t_posTemperatur=string_Input.find("\n");

        string_Ort =string_Input.substr(0,size_t_posOrt); //Der Ort aus den eingelesenen Daten wird in der Variable string_Ort gespeichert
        double_Temperatur = atof( (string_Input.substr(size_t_posOrt+1,size_t_posTemperatur-size_t_posOrt-1)).c_str() );//Die Temperatur aus den eingelesenen Daten wird in Double konvertiert und in der Variable string_Ort gespeichert

        DataContainer_Temperaturdaten->map_Temperaturen[string_Ort] = double_Temperatur; //Lege Ort und Temperatur in den Daten Container

        string_Input=string_Input.substr(size_t_posTemperatur+1,string_Input.length()); //"lösche" die verarbeiteten Daten aus dem Input String
    }

}

void Subject::getData()
{
    string string_Input;           //String für die eingelesenen Daten aus dem Internet
    string_Input = downloadData(); //Lade die Daten von der Website und lege sie in string_Input

    if(string_Input.empty() == true )//Fehlerbehandlung
    {
        DataContainer_Temperaturdaten->string_Metadaten="Fehler: Server nicht gefunden\nOder Website fehlerhaft";
    }
    else
    {
        if(string_Input.find("404 Not")!=std::string::npos)//Fehlerbehandlung wenn Internetseite nicht gefunden
            DataContainer_Temperaturdaten->string_Metadaten="Fehler 404, Seite nicht gefunden";

        else if(string_Input.find("Friedberger Wetterdienst")==std::string::npos )//Fehlerbehandlung bei fehlerhafter Internetseite
            DataContainer_Temperaturdaten->string_Metadaten="Fehler: Internetseite fehlerhaft";
        else
        {
            parseData(string_Input); //Wenn keine Fehler aufgetreten sind, parse Daten
        }
    }
    notify(); //Informiere Observer über neue Daten
              //Normalfall: Observer erhalten neue Temperaturdaten
              //Fehlerfall: Observer erhalten Fehlermeldung
}


