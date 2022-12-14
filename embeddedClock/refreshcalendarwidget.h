#ifndef REFRESHCALENDARWIDGET_H
#define REFRESHCALENDARWIDGET_H
#include <QThread>
#include <QString>
#include <QDateTime>
class refreshCalendarWidget : public QThread
{
    Q_OBJECT
public:
    refreshCalendarWidget();
    void getDate(int,int,int);
    int recordHour,recordMinute,recordSeconde;

signals:
    void sendDate(bool);
protected:
    void run();
public slots:
};
#endif // REFRESHCALENDARWIDGET_H
