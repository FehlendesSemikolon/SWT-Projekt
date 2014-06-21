#ifndef UPDATETIMER_H
#define UPDATETIMER_H

#include <QtCore>
#include <qtimer.h>
#include"subject.h"

#define UPDATEINTERVALL 60000 //1 Minute

class updateTimer : public QObject
{
    Q_OBJECT

private :
    Subject Subject_updatableSubject;

public:
    updateTimer(Subject s);
    QTimer *timer;

public slots:
    void TimerOverflow();


};


#endif // UPDATETIMER_H
