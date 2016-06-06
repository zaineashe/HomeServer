
#include "connection.h"

Connection::Connection()
{
	std::cout << "Initilising Boost Asio Socket Connections" << std::endl;
}

bool Connection::connect()
{
	std::cout << "Searching for connection...";
	// try and connect here
	
	// if can not connect
	std::cout << "failed" << std::endl;
	return false;
	
	// else
	/*
	 * std::cout << "successful: " << ip address << std:endl;
	 * return true
	 */
}