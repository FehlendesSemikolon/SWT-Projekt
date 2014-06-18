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

}


