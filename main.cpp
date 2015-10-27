#pragma comment(lib, "Ws2_32.lib")
#include "Server\webserver.h"
#include "Server\Socket.h"
#include "Server\Request_Handler.h"

int main()
{
	webserver(8080, Request_Handler);

	return 0;
}