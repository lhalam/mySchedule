#pragma comment(lib, "Ws2_32.lib")

#include "Server\webserver.h"
#include "Server\socket.h"
#include "Server\Request_Handler.h"
#include "Config\Config.h"
#include <map>

int main()
{
	Config conf("config.txt");
	map<string, map<string, string> > res = conf.getConfig();
	webserver(8080, Request_Handler);

	return 0;
}
