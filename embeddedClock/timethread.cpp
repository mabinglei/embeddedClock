#include "timethread.h"
#include <QTime>
timeThread::timeThread()
{
}
void timeThread::setTime(int hh,int mm,int ss)//设置自定义的时间
{
     qtime.setHMS(hh,mm,ss,0);
     recordTime = QDateTime::currentDateTime();//获取当前系统时间
}
void timeThread::run()
{
    while(1)//循环判断系统时间和手动设置的时间差是否为1秒
    {
        if (QDateTime::currentDateTime().secsTo(recordTime) != 0)
        {
            recordTime = QDateTime::currentDateTime();//更新记录的时间
            qtime = qtime.addSecs(1);//手动设置的时间+1秒
        }
        emit refreshTime(qtime.toString("hh:mm:ss"));//发送时间到主线程
        usleep(100);
     }
}
