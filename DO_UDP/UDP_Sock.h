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
	UDP_Sock(int post);//��ʼ�����ܷ��͵�Դ�˿�
	void set_to_addr(UDP_Addr add);//����Ŀ���ַ
	int Sendto(char *buf,int len);//��Ŀ���ַ������Ϣ
	int Recvfrom(char *buf, int len, UDP_Addr &addr);//��Դ�˿ڽ�����Ϣ����������Դ��addr
	void setWait(bool i);//����״̬ 0�� ��Ĭ�ϣ����� ; 1�� ������
};