#pragma once

#include "UDP_Sock.h"

int Init_DO_UDP()
{
	WSADATA wsd;

	char error[32] = "";
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		sprintf_s(error, "socket() failed ,Error Code:%d/n", WSAGetLastError());
		MessageBox(NULL, error, "Error", MB_OK);
		WSACleanup();
		return 1;
	}
}