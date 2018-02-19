#pragma once
#include <winsock2.h>  
#include <WS2tcpip.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"WS2_32.lib")  

class UDP_Addr
{
public:
	SOCKADDR_IN addr;
	int len = 0;

	UDP_Addr(char ip[16], int post);//ip is "any" or ip address ("233.233.233.233")
	char *GetIP(char *m);
	int   GetPost();
};