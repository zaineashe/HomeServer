#include "main.h"

//************ Main Class ************

Main::Main()
{
	LOG("Initilising Home Server V_0.2");
	
	boost::thread gui 	(boost::bind(&GUI::start, &this->_gui));
	boost::thread server(boost::bind(&Server::start, &this->_server));
	
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