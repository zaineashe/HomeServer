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
	bool isConnected();
	bool hasStreamed();
	bool hasBuffered();
	
private:
//************ VARIABLES ************
	boost::asio::io_service		_io;
	IP::tcp::acceptor			_acceptor;
	IP::tcp::socket				_socket;
	bool						_connected;
	bool						_streamed;
	bool						_buffered;
	std::vector<std::string>	_raw_file;
	std::vector<std::string>	_enc_file;
	
//************ FUNCTIONS ************
	
	void accept();
	void stream();
	void buffer();
	
//************ CONSTANTS ************
	static const int			_PORT_	= 13;
};

#endif	//	_SERVER_H_