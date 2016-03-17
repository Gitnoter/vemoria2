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
