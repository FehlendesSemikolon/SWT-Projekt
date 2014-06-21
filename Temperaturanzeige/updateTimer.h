#ifndef UPDATETIMER_H
#define UPDATETIMER_H

#include <QtCore>
#include <qtimer.h>
#include"subject.h"

#define UPDATEINTERVALL 1000

class updateTimer : public QObject
{
    Q_OBJECT

private :
    Subject testS;

public:
    updateTimer(Subject s);
    QTimer *timer;

public slots:
    void TimerOverflow();


};


#endif // UPDATETIMER_H
