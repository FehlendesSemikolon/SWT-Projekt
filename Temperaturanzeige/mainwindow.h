#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void setRohdaten(QString QStr_Temperaturdaten);
     void setMetadaten(QString QStr_Metadaten);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
