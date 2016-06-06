#ifndef _CONNECTION_H_
#define	_CONNECTION_H_

#include "libraries.h"

namespace ip = boost::asio::ip;

class Connection
{
public:
	Connection();
	
	void connect();
	bool isConnected();
	
private:
	boost::asio::io_service		_io;
	ip::tcp::acceptor			_acceptor;
	bool 						_connected;
};

#endif //_CONNECTION_H_