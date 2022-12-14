#include "mainwindow.h"
#include "timethread.h"
#include "ui_mainwindow.h"
#include <fcntl.h>
#include <unistd.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);//去除年和月标题
    ui->calendarWidget->setGridVisible(true);//网格模式
    ui->calendarWidget->setSelectionMode(QCalendarWidget::NoSelection);//设置不可修改
    ui->calendarWidget->setNavigationBarVisible(false);//去除导航栏
    ui->copyrightLabel->setText("Designed by mabinglei");
    TimeshowThread = new timeshowThread;
    TimeThread = new timeThread;
    RefreshCalendarWidget = new refreshCalendarWidget;
    alarmthread = new alarmThread;
    AlarmClockDialog = new alarmclockDialog;
    ringDialog = new RingDialog;
    time = new QTime;
    dhtthread = new dhtThread;
    TimeSetDialog = new timeSetDialog;
    isSet = false;//用于判断当前时间为系统时间还是手动设置的时间
    connect(TimeSetDialog,SIGNAL(sendSetTime(int,int,int,int,int,int)),this,SLOT(setTime(int,int,int,int,int,int)));
    connect(TimeshowThread,SIGNAL(sendTime(QString)),this,SLOT(DisplayTime(QString)));
    connect(TimeThread,SIGNAL(refreshTime(QString)),this,SLOT(updateTime(QString)));
    connect(RefreshCalendarWidget,SIGNAL(sendDate(bool)),this,SLOT(refreshDate(bool)));
    connect(alarmthread,SIGNAL(alarmRing(bool)),this,SLOT(alarmRing(bool)));
    connect(AlarmClockDialog,SIGNAL(sendAlarmTime(int,int,int,bool)),this,SLOT(getAlarm(int,int,int,bool)));
    connect(ringDialog,SIGNAL(offRing(bool)),this,SLOT(offRing(bool)));
    connect(dhtthread,SIGNAL(sendDHT(QString,QString)),this,SLOT(displayDHT(QString,QString)));
    TimeshowThread->start();
    RefreshCalendarWidget->start();
    dhtthread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayTime(QString time)//程序打开时默认显示系统时间
{
    ui->lcdNumber->display(time);
}

void MainWindow::updateTime(QString time)//手动设置时间后显示时间
{
    if (isSet)//如果是手动设置的时间则将时间传给myNow
        myNow = time;
    ui->lcdNumber->display(time);
}

void MainWindow::setTime(int hh,int mm, int ss,int yyyy,int MM,int dd)//设置LCD显示的时间为手动设置的时间
{
    QString str = QString("%1-%2-%3").arg(yyyy).arg(MM).arg(dd);
    QDate date = QDate::fromString(str,"yyyy-M-d");
    TimeshowThread->terminate();//将默认显示系统时间的线程关闭
    TimeThread->setTime(hh,mm,ss);
    TimeThread->start();
    isSet = true;//将标志设置为真，表示当前LCD显示的时间已经修改为手动设置的时间
    ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::refreshDate(bool need)//是否需要更新日期
{
    if (need)
    {
        QDate now = ui->calendarWidget->selectedDate().addDays(1);//日期+1
        ui->calendarWidget->setSelectedDate(now);
    }
    QTime time = QTime::fromString(myNow,"hh:mm:ss");
    RefreshCalendarWidget->getDate(time.hour(),time.minute(),time.second());
    ui->dateLabel->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
}

void MainWindow::displayDHT(QString temperature, QString humidity)//显示温湿度
{
    ui->temperatureLabel->setText(temperature);
    ui->humidityLabel->setText(humidity);
}

void MainWindow::getAlarm(int hh, int mm,int ss,bool isOn)//设置闹钟
{
    if (isOn)//闹钟是否启用
    {
        alarmthread->setAlarm(hh,mm,ss);
        alarmthread->start();
    }
}

void MainWindow::alarmRing(bool ring)//闹钟
{
   if (ring)//闹钟响起
   {
       ringDialog->setModal(true);
       ringDialog->show();
       //打开蜂鸣器
       Buzzerfd = open("/dev/buzzer", O_RDWR);
       val = 0;
       write(Buzzerfd, &val, 1);

   }
   if (isSet == true)
        *time = QTime::fromString(myNow,"hh:mm:ss");
   else
       time->setHMS(QDateTime::currentDateTime().time().hour(),QDateTime::currentDateTime().time().minute(),QDateTime::currentDateTime().time().second(),0);
   alarmthread->getTime(time->hour(),time->minute(),time->second());
}

void MainWindow::offRing(bool off)
{
    if (off)//关闭蜂鸣器
    {
        val = 1;
        write(Buzzerfd, &val, 1);
        ::close(Buzzerfd);
    }
}

void MainWindow::on_setButton_clicked()//手动设置时间按钮点击后调起TimeSetDialog
{
    TimeSetDialog->setModal(true);
    TimeSetDialog->show();
}

void MainWindow::on_setClockButton_clicked()//设置闹钟按钮点击时调起AlarmClockDialog
{

    AlarmClockDialog->setModal(true);
    AlarmClockDialog->show();
}


void MainWindow::on_syncButton_clicked()//网络校准按钮点击时发送HTTP GET请求，请求地址为http://localhost:8000/time，响应体为格式化后的yyyy-MM-dd
{
    // 创建一个QNetworkAccessManager对象，用于发送网络请求
     QNetworkAccessManager manager;
     // 发送一个GET请求到http://localhost:8000/time
     QNetworkReply* reply = manager.get(QNetworkRequest(QUrl("http://study.mabinglei.com:8000/time")));
     // 等待响应完成
     QEventLoop loop;
     QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
     loop.exec();
     // 获取响应体的内容
     QByteArray responseData = reply->readAll();
     // 将响应体的内容转换为字符串
     QString responseString = QString::fromUtf8(responseData);
     QDateTime networkTime = QDateTime::fromString(responseString,"yyyy-MM-dd hh:mm:ss");
     setTime(networkTime.time().hour(),networkTime.time().minute(),networkTime.time().second(),networkTime.date().year(),networkTime.date().month(),networkTime.date().day());
}

