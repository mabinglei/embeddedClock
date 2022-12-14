#include "timeshowthread.h"
#include <QTime>
timeshowThread::timeshowThread()
{
}
void timeshowThread::run()
{
    while(1)//循环获取系统时间并发送信号到主线程
    {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_time = current_date_time.toString("hh:mm:ss");
        emit sendTime(current_time);
        sleep(1);
     }
}
