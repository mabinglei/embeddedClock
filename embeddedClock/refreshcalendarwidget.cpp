#include "refreshcalendarwidget.h"
#include <QTime>
refreshCalendarWidget::refreshCalendarWidget()
{
}
void refreshCalendarWidget::getDate(int hh,int mm,int ss)//获取当前时间
{
    recordHour = hh;
    recordMinute = mm;
    recordSeconde = ss;
}
void refreshCalendarWidget::run()
{
    while(1)//循环判断是否需要对日历进行+1操作
    {
        if (recordHour == 23 && recordMinute == 59 && recordSeconde == 59)
            emit sendDate(true);
        else
            emit sendDate(false);
        sleep(1);
     }
}
