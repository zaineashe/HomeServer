#include "Server.h"

Server::Server()
	: _acceptor(Server::_io, IP::tcp::endpoint(IP::tcp::v4(), Server::_PORT_)),
	  _socket(Server::_io)
{
	LOG("Initilising Backend Server Communications");
	
	Server::_connected = false;
}

Server::~Server()
{
	LOG("Terminating Backend Server Communcations");
}


void Server::start()
{
	LOG("Initialising Server communication socket acceptor searching");
	Server::accept();
}

bool Server::isConnected()
{
	return Server::_connected;
}

void Server::accept()
{
	try
	{
		LOG("Server Waiting for socket connection...");
		Server::_acceptor.accept(Server::_socket);
		Server::_connected = true;
		LOG("Server Connected");
	}
	catch (...) // What Exception? Need to be boost::exception?
	{
		LOG("ERROR");
	}
}