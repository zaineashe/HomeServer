#include "Server.h"

Server::Server()
	: _acceptor(Server::_io, IP::tcp::endpoint(IP::tcp::v4(), Server::_PORT_)),
	  _socket(Server::_io)
{
	LOG("Initilising Backend Server Communications");
}

Server::~Server()
{
	LOG("Terminating Backend Server Communcations");
}


void Server::start()
{
	LOG("Initialising Server communication socket acceptor searching");
	
	try
	{
		LOG("Server Waiting for socket connection...");
		Server::_acceptor.accept(Server::_socket);
		LOG("Server Connected");
	}
	catch (...)
	{
		LOG("ERROR");
	}
}