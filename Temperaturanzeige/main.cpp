#include "mainwindow.h"
#include "qcustomplot.h"
#include "subject.h"
#include "observerdata.h"
#include "observerrohform.h"
#include "observermetadaten.h"
#include "oberverPunktdiagramm.h"
#include "observerBalkendiagramm.h"
#include <QApplication>

int main(int argc, char *argv[])
{

/*--------------------Application initiallisierung--------------------------------------------------------------------*/
    QApplication QApplication_app(argc, argv); //generiert durch IDE
    MainWindow* MainWindow_startupMainWindow = new MainWindow();
    MainWindow_startupMainWindow->show();


/*--------------------Subject erstellen--------------------------------------------------------------------------------*/
    Subject *Subject_mainSubject = new Subject;
    MainWindow_startupMainWindow->addSubject(Subject_mainSubject);


/*--------------------Erstellen der Observer--------------------------------------------------------------------------*/
    ObserverData* ObserverRohform_Rohform = new ObserverRohform(MainWindow_startupMainWindow);
    ObserverData* ObserverMetadaten_Metadaten = new ObserverMetadaten(MainWindow_startupMainWindow);
    ObserverData* ObserverPunktdiagramm_Punktdiagramm = new ObserverPunktdiagramm(MainWindow_startupMainWindow);
    ObserverData* ObserverBalkendiagramm_Balkendiagramm = new ObserverBalkendiagramm(MainWindow_startupMainWindow);


/*--------------------Anmelden der Observer bei dem Subject----------------------------------------------------------*/
    Subject_mainSubject->attach(ObserverRohform_Rohform);
    Subject_mainSubject->attach(ObserverMetadaten_Metadaten);
    Subject_mainSubject->attach(ObserverPunktdiagramm_Punktdiagramm);
    Subject_mainSubject->attach(ObserverBalkendiagramm_Balkendiagramm);


/*--------------------Erstmalig Daten abrufen und ausgeben---------------------------------------------------------*/
    Subject_mainSubject->getData();





    return QApplication_app.exec();
}
