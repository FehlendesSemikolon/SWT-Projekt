#include "updateTimer.h"

updateTimer::updateTimer(Subject s)
{
    testS = s;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerOverflow()));
    timer->start(UPDATEINTERVALL);
}

void updateTimer::TimerOverflow()
{
    testS.getData();

}
