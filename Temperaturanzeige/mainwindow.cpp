#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRohdaten(QString QStr_Temperaturdaten)
{
    ui->label_Rohdaten->setText(QStr_Temperaturdaten);
}

void MainWindow::setMetadaten(QString QStr_Metadaten)
{
    ui->label_Metadaten->setText(QStr_Metadaten);
}

void MainWindow::setPunktdiagramm(QVector<double> x, QVector<double> y)
{
    ui->widget_Punktdiagramm->graph(0)->setData(x,y);
    ui->widget_Punktdiagramm->replot();
}


void MainWindow::setBalkendiagramm(QVector<double> x, QVector<double> y)
{
    myBars->setData(x, y);
    ui->widget_Balkendiagramm->replot();
}


void MainWindow::initPunktdiagramm()
{
    QVector<QString> QString_Labels;

    ui->widget_Punktdiagramm->addGraph();
    ui->widget_Punktdiagramm->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);


    ui->widget_Punktdiagramm->xAxis->setLabel("Stadt");
    ui->widget_Punktdiagramm->yAxis->setLabel("Temperatur");

    ui->widget_Punktdiagramm->xAxis->setAutoTickStep(false);
    ui->widget_Punktdiagramm->xAxis->setTickStep(1);

    QString_Labels << QString::fromUtf8("Friedberg") << QString::fromUtf8("Giessen") <<
                      QString::fromUtf8("Butzbach") << QString::fromUtf8("Frankfurt")<<
                      QString::fromUtf8("Darmstadt") << QString::fromUtf8("Offenbach");

    ui->widget_Punktdiagramm->xAxis->setAutoTickLabels(false);

    ui->widget_Punktdiagramm->xAxis->setTickVectorLabels(QString_Labels);

    ui->widget_Punktdiagramm->xAxis->setRange(0,5.5);
    ui->widget_Punktdiagramm->yAxis->setRange(0, 100);

     ui->widget_Balkendiagramm->replot();


}

void MainWindow::initBalkendiagramm()
{

    QVector<QString> QString_Labels;

    myBars = new QCPBars(ui->widget_Balkendiagramm->xAxis, ui->widget_Balkendiagramm->yAxis);
    ui->widget_Balkendiagramm->addPlottable(myBars);


    ui->widget_Balkendiagramm->xAxis->setLabel("Stadt");
    ui->widget_Balkendiagramm->yAxis->setLabel("Temperatur");

    ui->widget_Balkendiagramm->xAxis->setAutoTickStep(false);
    ui->widget_Balkendiagramm->xAxis->setTickStep(1);

    QString_Labels << QString::fromUtf8("") << QString::fromUtf8("Friedberg") << QString::fromUtf8("Giessen") <<
                      QString::fromUtf8("Butzbach") << QString::fromUtf8("Frankfurt")<<
                      QString::fromUtf8("Darmstadt") << QString::fromUtf8("Offenbach");

    ui->widget_Balkendiagramm->xAxis->setAutoTickLabels(false);
    ui->widget_Balkendiagramm->xAxis->setTickVectorLabels(QString_Labels);

    ui->widget_Balkendiagramm->xAxis->setRange(0,6.5);
    ui->widget_Balkendiagramm->yAxis->setRange(0, 100);

    ui->widget_Balkendiagramm->replot();



}
