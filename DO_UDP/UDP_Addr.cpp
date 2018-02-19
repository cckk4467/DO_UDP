#include "UDP_Addr.h"

UDP_Addr::UDP_Addr(char ip[16], int post)
{
	if (strcmp(ip, "any") == 0)
		addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	else
		inet_pton(AF_INET, ip, &addr.sin_addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(post);

	len = sizeof(addr);
}

char * UDP_Addr::GetIP(char *m)
{
	inet_ntop(AF_INET, &addr.sin_addr, m, 16);
	return m;
}

int UDP_Addr::GetPost()
{
	return ntohs(addr.sin_port);
}
