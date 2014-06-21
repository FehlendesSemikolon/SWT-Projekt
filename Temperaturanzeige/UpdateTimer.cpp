#include "updateTimer.h"

updateTimer::updateTimer(Subject s)
{
    Subject_updatableSubject = s;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerOverflow()));
    timer->start(UPDATEINTERVALL);
}

void updateTimer::TimerOverflow()
{
    Subject_updatableSubject.getData();

}
