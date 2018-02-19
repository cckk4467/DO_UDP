#include <iostream>
#include "DO_UDP.h"
using namespace std;
int main()
{
	Init_DO_UDP();
 
	UDP_Sock s(5000);
	char re[32] = "";
	UDP_Addr ad("any", 0);
	s.Recvfrom(re, 32, ad);
	char ip[16] = "";
	cout << re << " " << ad.GetIP(ip) << " " << ad.GetPost() << endl;
}
