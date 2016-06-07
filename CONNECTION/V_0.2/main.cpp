#include "main.h"

//************ Main Class ************

Main::Main()
{
	LOG("Initilising Home Server V_0.2");
	
	Main::_gui.setMessage("Waiting For Connection");
	
	boost::thread gui 	(boost::bind(&GUI::start, &this->_gui));
	boost::thread server(boost::bind(&Server::start, &this->_server));
	
	while(true)
	{
		if (Main::_server.isConnected())
		{
			Main::_gui.setMessage("Streaming Media");
			break;
		}
		WAIT(1);
	}
	
	gui.join();
	server.join();
}

Main::~Main()
{
	LOG("Terminating Home Server V_0.2");
}

//************ Main Function ************

int main()
{
	Main();
}