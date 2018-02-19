#pragma once
#include <winsock2.h>  
#include "UDP_Addr.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"WS2_32.lib")  

class UDP_Sock
{
private:
	SOCKET  s;
	UDP_Addr addr;
	UDP_Addr to_addr;
	UDP_Sock();
public:
	UDP_Sock(int post);//初始化接受发送的源端口
	void set_to_addr(UDP_Addr add);//设置目标地址
	int Sendto(char *buf,int len);//向目标地址发送信息
	int Recvfrom(char *buf, int len, UDP_Addr &addr);//从源端口接受消息并带出发送源的addr
	void setWait(bool i);//阻塞状态 0： （默认）阻塞 ; 1： 不阻塞
};