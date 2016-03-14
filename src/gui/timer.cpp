#include "timer.h"
#include "QtCore"
#include "QDebug"

timer::timer()
{
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(MySlot()));

    //start every second
    time->start(1000);

}


//count the copy time
//something wrong here maybe
quint64 timer::MySlot(quint64 size){

    quint64 speed = size / 1024 / 1;

    qDebug() << "Timer execute";
    return speed;
}

void timer::timerStop(){
    time->stop();
}
