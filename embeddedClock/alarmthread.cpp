#include "alarmthread.h"
#include <QTime>
alarmThread::alarmThread()
{
}
void alarmThread::setAlarm(int hh,int mm,int ss)//设置闹钟时间
{
     alarmTime.setHMS(hh,mm,ss,0);
}
void alarmThread::getTime(int hh,int mm,int ss)//获取当前时间
{
     nowTime.setHMS(hh,mm,ss,0);
}

void alarmThread::run()
{
    while(1)//循环判断是否响起闹钟
    {
        if (alarmTime.hour() == nowTime.hour() && alarmTime.minute() == nowTime.minute() && alarmTime.second() == nowTime.second())
        {
            emit alarmRing(true);
        }
        else
            emit alarmRing(false);
        msleep(100);
     }
}
