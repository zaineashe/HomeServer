#ifndef _MAIN_H_
#define	_MAIN_H_

#include "libraries.h"
#include "connection.h"
#include "interface.h"

class Main
{
public:
	Main(boost::asio::io_service&);
	
private:
// ************ VARIABLES ************
	boost::asio::deadline_timer		_connection_timer;
	boost::asio::deadline_timer		_interface_timer;
	Connection* 					_connection;
	Interface* 						_interface;
	
// ************ FUNCTIONS ************
	void runConnection();
	void runInterface();
	
// ************ CONSTANTS ************
	static const int _delay = 1; 
};

#endif // _MAIN_H_