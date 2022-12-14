#ifndef ALARMTHREAD_H
#define ALARMTHREAD_H
#include <QThread>
#include <QString>
#include <QDateTime>
class alarmThread : public QThread
{
    Q_OBJECT
public:
    QTime alarmTime,nowTime;
    QDateTime recordTime;
    alarmThread();
    void setAlarm(int,int,int);
    void getTime(int,int,int);
signals:
    void alarmRing(bool);
protected:
    void run();
public slots:
};
#endif // ALARMTHREAD_H
