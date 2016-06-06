#include "interface.h"

Interface::Interface()
{
#ifdef _LOG_
	std::cout << "Initilising Interface Protocols" << std::endl;
#endif
}

void Interface::update(std::string message)
{
//#ifdef _LOG_
	std::cout << "Updating Screen: " << message << std::endl;
//#endif
}