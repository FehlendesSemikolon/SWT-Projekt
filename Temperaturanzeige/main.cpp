#include "mainwindow.h"
#include "qcustomplot.h"
#include "subject.h"
#include "observerdata.h"
#include "observerrohform.h"
#include "observermetadaten.h"
#include "oberverPunktdiagramm.h"

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

    mySubject.attach(ObserverRohform_Rohform);
    mySubject.attach(ObserverMetadaten_Metadaten);
    mySubject.attach(ObserverPunktdiagramm_Punktdiagramm);

    mySubject.getData();

    return a.exec();
}
