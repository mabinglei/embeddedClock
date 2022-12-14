#include "dhtthread.h"
#include <fcntl.h>
#include <unistd.h>

dhtThread::dhtThread()
{
}
void dhtThread::run()//打开/dev/dht11并循环读取温湿度数据
{

    char dht[16];
    int dhtfd = open("/dev/dht11",O_RDONLY);

    while(1)
    {
        read(dhtfd,dht,16);
        emit sendDHT(QString::number(dht[2]),QString::number(dht[0]));
        sleep(1);
     }
}
