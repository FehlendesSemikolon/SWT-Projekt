#include "mainwindow.h"
#include "qcustomplot.h"
#include "subject.h"
#include "observerdata.h"
#include "observerrohform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->show();
    Subject mySubject;
    ObserverData* myObserverRohform = new ObserverRohform(w);
    mySubject.attach(myObserverRohform);
    mySubject.getData();

    return a.exec();
}
