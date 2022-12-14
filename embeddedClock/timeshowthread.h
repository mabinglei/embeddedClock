#ifndef TIMESHOWTHREAD_H
#define TIMESHOWTHREAD_H
#include <QThread>
#include <QString>
class timeshowThread : public QThread
{
    Q_OBJECT
public:
    timeshowThread();
signals:
    void sendTime(QString);
protected:
    void run();
public slots:
};
#endif // TIMESHOWTHREAD_H
