#ifndef DHTTHREAD_H
#define DHTTHREAD_H
#include <QThread>
#include <QString>
class dhtThread : public QThread
{
    Q_OBJECT
public:
    dhtThread();
signals:
    void sendDHT(QString,QString);
protected:
    void run();
private:
public slots:
};
#endif // DHTTHREAD_H
