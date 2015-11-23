#pragma comment(lib, "Ws2_32.lib")

#include "Server\webserver.h"
#include "Server\socket.h"
#include "Server\Request_Handler.h"

#include "globals.h"

int main()
{
	int port = 8080;

	try
	{
		port = stoi(config["myschedule"]["port"]);
	} catch (...) { }
	
	webserver(port, Request_Handler);
	
	return 0;
}
