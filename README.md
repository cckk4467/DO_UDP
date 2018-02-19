# DO_UDP
一个简单的UDP封装类

*这是一个简单的UDP演示*

## Server
```
#include<iostream>
#include"DO_UDP"
using namespace std;
int main()
{
    Init_DO_UDP();//初始化
    UDP_Sock s(2333);//监听数据时，在本地端口2333
    char me[23]="",ip[16]="";
    UDP_Addr ClientAddr;
    //s.setWait(1);  改为非阻塞模式
    s.Recvfrom(me,23,ClientAddr);
    cout<<s.GetIP(ip)<<"说:"<<me<<endl;
}
```

## Client
```
#include<iostream>
#include"DO_UDP"
using namespace std;
int main()
{
    Init_DO_UDP();//初始化
    UDP_Sock s(6666);//监听数据时，在本地端口2333
    s.set_to_addr(UDP_Addr("233.233.233.233",2333));//设置目标的IP与端口
    s.Send("Hello,DO_UDP",18);
}
```

以上就是一个最简单的使用例子，您可以在此基础上构建更复杂的功能与内容。QwQ
顺便，2018苟年大吉！