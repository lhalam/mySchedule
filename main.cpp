#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable: 4251)

#include "Server\webserver.h"
#include "Server\socket.h"
#include "Server\Request_Handler.h"

int main()
{
	webserver(8080, Request_Handler);

	return 0;
}
