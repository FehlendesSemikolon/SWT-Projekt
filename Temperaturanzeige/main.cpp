#include "mainwindow.h"
#include "qcustomplot.h"
#include "subject.h"
#include "observerdata.h"
#include "observerrohform.h"
#include "observermetadaten.h"
#include "oberverPunktdiagramm.h"
#include "observerBalkendiagramm.h"

#include "updateTimer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->show();

    Subject mySubject;
    ObserverData* ObserverRohform_Rohform = new ObserverRohform(w);
    ObserverData* ObserverMetadaten_Metadaten = new ObserverMetadaten(w);
    ObserverData* ObserverPunktdiagramm_Punktdiagramm = new ObserverPunktdiagramm(w);
    ObserverData* ObserverBalkendiagramm_Balkendiagramm = new ObserverBalkendiagramm(w);

    mySubject.attach(ObserverRohform_Rohform);
    mySubject.attach(ObserverMetadaten_Metadaten);
    mySubject.attach(ObserverPunktdiagramm_Punktdiagramm);
    mySubject.attach(ObserverBalkendiagramm_Balkendiagramm);

    updateTimer myTimer(mySubject);



    //mySubject.getData();

    return a.exec();
}
