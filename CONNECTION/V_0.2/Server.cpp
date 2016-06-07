#include "Server.h"

Server::Server()
	: _acceptor(Server::_io, IP::tcp::endpoint(IP::tcp::v4(), Server::_PORT_)),
	  _socket(Server::_io)
{
	LOG("Initilising Backend Server Communications");
	
	Server::_connected 	= false;
	Server::_streamed	= false;
	Server::_buffered	= false;
}

Server::~Server()
{
	LOG("Terminating Backend Server Communcations");
}


void Server::start()
{
	LOG("Initialising Server communication socket acceptor searching");
	Server::accept();
	Server::stream();
	Server::buffer();
}

bool Server::isConnected()
{
	return Server::_connected;
}

bool Server::hasStreamed()
{
	return Server::_streamed;
}

bool Server::hasBuffered()
{
	return Server::_buffered;
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
	catch (std::exception& e) // What Exception? Need to be boost::exception?
	{
		LOG("ERROR: ");
	}
}

void Server::stream()
{
//	try
//	{
//		while (true)
//		{
//			std::vector<char> buffer;
//			boost::system::error_code error;
//			
//			size_t length = Server::_socket.read_some(boost::asio::buffer(buffer), error);
//			
//			if (error == boost::asio::error::eof)
//			{
//				Server::_streamed = true;
//				break;
//			}
//			else if (error)
//				throw boost::system::system_error(error);
//			else
//			{
//				LOG("MSG: " + length);
//				break; // Needed break
//				//file.append(message);
//			}
//			WAIT(1);
//		}
//	}
//	catch (std::exception& e)
//	{
//		LOG("ERROR");
//	}
}

void Server::buffer()
{
	
}