/// \file
/// \brief	Vemoria timer header file
/// \ingroup	gui
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#ifndef TIMER_H
#define TIMER_H
#include <QtCore>

class timer : public QObject
{
    Q_OBJECT

public:
    timer();
    QTimer *time;
    int i = 0;
    int counter;
    void timerStop();

public slots:
    quint64 MySlot(quint64 size);

};

#endif // TIMER_H
