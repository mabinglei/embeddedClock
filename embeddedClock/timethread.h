#ifndef TIMETHREAD_H
#define TIMETHREAD_H
#include <QThread>
#include <QString>
#include <QDateTime>
class timeThread : public QThread
{
    Q_OBJECT
public:
    QTime qtime;
    QDateTime recordTime;
    timeThread();
    void setTime(int,int,int);
signals:
    void refreshTime(QString);
protected:
    void run();
public slots:
};
#endif // TIMETHREAD_H
