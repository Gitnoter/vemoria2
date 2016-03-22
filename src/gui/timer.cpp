/// \file
/// \brief	Vemoria timer cpp file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

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
