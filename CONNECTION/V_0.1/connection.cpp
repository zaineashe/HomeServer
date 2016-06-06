
#include "connection.h"

Connection::Connection()
	: _acceptor(Connection::_io, ip::tcp::endpoint(ip::tcp::v4(), 13))
{
#ifdef _LOG_
	std::cout << "Initilising Boost Asio Socket Connections" << std::endl;
#endif
	
	Connection::_connected = false;
}


void Connection::connect()
{
#ifdef _LOG_
	std::cout << "Searching for connection...";
#endif
	
	ip::tcp::socket socket(Connection::_io);
	Connection::_acceptor.accept(socket);
	
	std::cout << "CONNECTED" << std::endl;
	
#ifdef _LOG_
	std::cout << "failed" << std::endl;
#endif
}

bool Connection::isConnected()
{
	return Connection::_connected;
}