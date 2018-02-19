#include "UDP_Sock.h"
#include <cstdio>

UDP_Sock::UDP_Sock(int post) :addr(UDP_Addr("any", post)), to_addr(UDP_Addr("", 0))
{
	char error[64] = "";
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s == INVALID_SOCKET)
	{
		sprintf_s(error, "socket() failed ,Error Code:%d/n", WSAGetLastError());
		MessageBox(NULL, error, "Error",MB_OK);
		WSACleanup();
		return;
	}
	if (bind(s, (SOCKADDR*)&addr.addr, addr.len) == -1)
	{
		sprintf_s(error, "bind() failed ,Error Code:%d/n", WSAGetLastError());
		MessageBox(NULL, error, "Error", MB_OK);
		WSACleanup();
		return;
	}
}

void UDP_Sock::set_to_addr(UDP_Addr add)
{
	to_addr = add;
}

int UDP_Sock::Sendto(char * buf, int len)
{
	return sendto(s, buf, len, 0, (SOCKADDR*)&to_addr.addr, to_addr.len);
}

int UDP_Sock::Recvfrom(char * buf, int len, UDP_Addr & addr)
{
	return recvfrom(s, buf, len, 0, (SOCKADDR*)&addr.addr, &addr.len);
}

void UDP_Sock::setWait(bool i)
{
	ioctlsocket(s, FIONBIO, (u_long FAR*) &i);
}
