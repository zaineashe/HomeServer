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
	LOG("Initialised Streaming");
	try 
	{
		size_t length;
		uint32_t message_size;
		std::string message;
		
		boost::asio::streambuf buffer;
		
		boost::asio::streambuf::mutable_buffers_type size_buffer
			= buffer.prepare(4);
		
		length = Server::_socket.receive(size_buffer);
		buffer.commit(length);
		
		std::istream is(&buffer);
		is >> message_size;
		
		boost::asio::streambuf::mutable_buffers_type message_buffer
			= buffer.prepare(message_size);
		length = Server::_socket.receive(message_buffer);
		buffer.commit(length);
		
		std::istream ismsg(&buffer);
		std::getline(ismsg, message);
		
		std::cout << message << std::endl;
	}
	catch (std::exception& e)
	{
		LOG("ERROR: ");
	}
}

void Server::buffer()
{
	LOG("Initialised Buffering");
}