#include "library.h"
#include "GUI.h"
#include "Server.h"

void waitForConnection(GUI* gui, Server* server)
{
	while(true)
	{
		if (server->isConnected())
		{
			gui->setMessage("Streaming Media");
			break;
		}
		WAIT(1);
	}
}

void waitForStream(GUI* gui, Server* server)
{
	while(true)
	{
		if (server->hasStreamed())
		{
			gui->setMessage("Buffering Media");
			break;
		}
		WAIT(1);
	}
}

int main()
{
	LOG("Initilising Home Server V_0.2");
	
	GUI 	gui;
	Server 	server;
	
	gui.setMessage("Waiting For Connection");
	
	boost::thread t_gui 	(boost::bind(&GUI::start, &gui));
	boost::thread t_server	(boost::bind(&Server::start, &server));
	
	waitForConnection(&gui, &server);
	waitForStream(&gui, &server);
	
	t_gui.join();
	t_server.join();
}