
#include "connection.h"

Connection::Connection()
{
#ifdef _LOG_
	std::cout << "Initilising Boost Asio Socket Connections" << std::endl;
#endif
}

bool Connection::connect()
{
#ifdef _LOG_
	std::cout << "Searching for connection...";
#endif
	// try and connect here
	
//	//TEMPORARY
//#ifdef _LOG_
//	std::cout << "Successful: 10.0.0.4" << std::endl;
//#endif
//	return true;
//	//TEMPORARY
	
	// if can not connect
#ifdef _LOG_
	std::cout << "failed" << std::endl;
#endif
	return false;
	
	// else
	/*
	 * std::cout << "successful: " << ip address << std:endl;
	 * return true
	 */
}