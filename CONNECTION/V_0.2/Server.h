#ifndef 	_SERVER_H_
#define		_SERVER_H_

#include "library.h"

namespace IP = boost::asio::ip;

class Server
{
public:
	Server();
	~Server();
	
	void start();
	
private:
//************ VARIABLES ************
	boost::asio::io_service		_io;
	IP::tcp::acceptor			_acceptor;
	IP::tcp::socket				_socket;
	
//************ CONSTANTS ************
	static const int			_PORT_	= 13;
};

#endif	//	_SERVER_H_