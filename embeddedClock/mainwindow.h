#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timeshowthread.h"
#include "timesetdialog.h"
#include "alarmclockdialog.h"
#include "timethread.h"
#include "refreshcalendarwidget.h"
#include "alarmthread.h"
#include "ringdialog.h"
#include "dhtthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    timeshowThread *TimeshowThread;
    timeThread *TimeThread;
    QTime *time;
    QString myNow;
    refreshCalendarWidget *RefreshCalendarWidget;
    timeSetDialog *TimeSetDialog;
    alarmclockDialog *AlarmClockDialog;
    alarmThread *alarmthread;
    RingDialog *ringDialog;
    dhtThread *dhtthread;
    bool isSet;
    int Buzzerfd,val;

private slots:
    void DisplayTime(QString);
    void on_setButton_clicked();
    void on_setClockButton_clicked();
    void updateTime(QString);
    void setTime(int,int,int,int,int,int);
    void refreshDate(bool);
    void getAlarm(int,int,int,bool);
    void alarmRing(bool);
    void on_syncButton_clicked();
    void offRing(bool);
    void displayDHT(QString,QString);
};
#endif // MAINWINDOW_H
