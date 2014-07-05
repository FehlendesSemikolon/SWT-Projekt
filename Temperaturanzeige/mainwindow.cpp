#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    QTimer_DataUpdateTimer = new QTimer(this); //Neuen Timer erstellen
    connect(QTimer_DataUpdateTimer, SIGNAL(timeout()), this, SLOT(TimerOverflow())); //Erstellten Timer in der "TimerTimerOverflow"-Funktion verknüpfen
    QTimer_DataUpdateTimer->start(UPDATEINTERVALL); //Timer starten und Überlaufintervall festlegen

     ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerOverflow()
{
    Subject_updateableSubject->getData(); //Neue Daten vom Modell anfordern
}


void MainWindow::addSubject(Subject *s)
{
    Subject_updateableSubject = s; //Verbindung zwischen Controller und Modell
}

void MainWindow::setRohdaten(QString QStr_Temperaturdaten)
{
    ui->label_Rohdaten->setText(QStr_Temperaturdaten); //Ausgeben der Daten als Zeichenkette
}

void MainWindow::setMetadaten(QString QStr_Metadaten)
{
    ui->label_Metadaten->setText(QStr_Metadaten);//Ausgeben der Metadaten als Zeichenkette
}

void MainWindow::setPunktdiagramm(QVector<double> x, QVector<double> y, QVector<QString> QString_Labels)
{
    ui->widget_Punktdiagramm->xAxis->setTickVectorLabels(QString_Labels); //x-Achenbeschriftung setzen
    ui->widget_Punktdiagramm->graph(0)->setData(x,y); //Graph neue Daten zuweisen
    ui->widget_Punktdiagramm->replot(); //Graph auf GUI zeichnen
}


void MainWindow::setBalkendiagramm(QVector<double> x, QVector<double> y,  QVector<QString> QString_Labels)
{
    ui->widget_Balkendiagramm->xAxis->setTickVectorLabels(QString_Labels); //x-Achenbeschriftung setzen
    QCPBars_Bars->setData(x, y); //Graph neue Daten zuweisen
    ui->widget_Balkendiagramm->replot();//Graph auf GUI zeichnen
}


void MainWindow::initPunktdiagramm()
{

    ui->widget_Punktdiagramm->addGraph(); //Graph in das noch leere Koordinatensystem einfügen
    ui->widget_Punktdiagramm->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc); //Anpassen des Designs der Punkte

    //Achen beschriften
    ui->widget_Punktdiagramm->xAxis->setLabel("Stadt");
    ui->widget_Punktdiagramm->yAxis->setLabel("Temperatur");

    //Automatische Schrittgrößenfestlegung der x-Achse abschalten
    ui->widget_Punktdiagramm->xAxis->setAutoTickStep(false);
    ui->widget_Punktdiagramm->xAxis->setTickStep(1);

    ui->widget_Punktdiagramm->xAxis->setAutoTickLabels(false); //Automatische Achsenbeschriftung abschalten

    //Start und Endwerte der Achsen festlegen
    ui->widget_Punktdiagramm->xAxis->setRange(0,5.5);
    ui->widget_Punktdiagramm->yAxis->setRange(0, 100);

     ui->widget_Balkendiagramm->replot();//Konfigurierten Graph auf GUI zeichnen


}

void MainWindow::initBalkendiagramm()
{

    QCPBars_Bars = new QCPBars(ui->widget_Balkendiagramm->xAxis, ui->widget_Balkendiagramm->yAxis); //Erstellen eines neuen QCustomPlot-Balkenobjekts
    ui->widget_Balkendiagramm->addPlottable(QCPBars_Bars); //Hinzufügen des Balkenobjekts in das noch leere Koordinatensystem


    //Achen beschriften
    ui->widget_Balkendiagramm->xAxis->setLabel("Stadt");
    ui->widget_Balkendiagramm->yAxis->setLabel("Temperatur");

    //Automatische Schrittgrößenfestlegung der x-Achse abschalten
    ui->widget_Balkendiagramm->xAxis->setAutoTickStep(false);
    ui->widget_Balkendiagramm->xAxis->setTickStep(1);


    ui->widget_Balkendiagramm->xAxis->setAutoTickLabels(false);//Automatische Achsenbeschriftung abschalten

    //Start und Endwerte der Achsen festlegen
    ui->widget_Balkendiagramm->xAxis->setRange(0,6.5);
    ui->widget_Balkendiagramm->yAxis->setRange(0, 100);

    ui->widget_Balkendiagramm->replot();//Konfigurierten Graph auf GUI zeichnen



}
