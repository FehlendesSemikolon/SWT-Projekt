#include "mainwindow.h"
#include "ui_mainwindow.h"

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
