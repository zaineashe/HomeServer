#include "main.h"

Main::Main(boost::asio::io_service& io)
	: _connection_timer	(io, boost::posix_time::seconds(Main::_DELAY)),
	  _interface_timer	(io, boost::posix_time::seconds(Main::_DELAY))
{
#ifdef _LOG_
	std::cout << "Initilising Host Machine Home Server" << std::endl;
#endif

	*Main::_connection 	= Connection();
	*Main::_interface 	= Interface();
	
	_connection_timer.async_wait(boost::bind(&Main::runConnection, this));
	_interface_timer.async_wait(boost::bind(&Main::runInterface, this));
}

void Main::runConnection()
{
	if (Main::_connection->connect())
	{
		Main::_message = "Streaming Movie";
		
		Main::_connection_timer.expires_at(Main::_connection_timer.expires_at()
				+ boost::posix_time::seconds(Main::_DELAY));
		Main::_connection_timer.async_wait(boost::bind(&Main::streamConnection, this));
	}
	else
	{
		Main::_message = "Waiting For Connection";
		
		Main::_connection_timer.expires_at(Main::_connection_timer.expires_at()
				+ boost::posix_time::seconds(Main::_DELAY));
		Main::_connection_timer.async_wait(boost::bind(&Main::runConnection, this));
	}
}

void Main::streamConnection()
{
	/*
	 * get message from client
	 * if message == EOF
	 * {
	 *  	Main::_message = "Buffering"
	 *  	
	 *  	Main::bufferConnection()
	 * }
	 * else
	 * {
	 * 		get percentage done
	 * 		std::cout << "streaming... " << percentage << std::endl;
	 * 	 	add message to file for encoding
	 * 	 	
	 * 	 	async.wait(recursive Call)
	 * }
	 */
	
	int percentage = 0;
#ifdef _LOG_
	std::cout << "Streaming... " << percentage << "%" << std::endl;
#endif
	
	
	Main::_connection_timer.expires_at(Main::_connection_timer.expires_at()
			+ boost::posix_time::seconds(Main::_DELAY));
	Main::_connection_timer.async_wait(boost::bind(&Main::streamConnection, this));
}

void Main::runInterface()
{
	Main::_interface->update(Main::_message);
	
	Main::_interface_timer.expires_at(Main::_interface_timer.expires_at()
			+ boost::posix_time::seconds(Main::_DELAY));
	Main::_interface_timer.async_wait(boost::bind(&Main::runInterface, this));
}



int main()
{
	boost::asio::io_service io;
	Main root(io);
	io.run();
}
