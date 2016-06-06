#include "main.h"

Main::Main(boost::asio::io_service& io)
	: _connection_timer	(io, boost::posix_time::seconds(Main::_delay)),
	  _interface_timer	(io, boost::posix_time::seconds(Main::_delay))
{
	std::cout << "Initilising Host Machine Home Server" << std::endl;

	*Main::_connection 	= Connection();
	*Main::_interface 	= Interface();
	
	_connection_timer.async_wait(boost::bind(&Main::runConnection, this));
	_interface_timer.async_wait(boost::bind(&Main::runInterface, this));
}

void Main::runConnection()
{
	Main::_connection->connect();
	/*	Will need to do this:
	 * if (Main::_connection->connect())
	 * {
	 * 		update register for now loading
	 * 		_connection_timer.async_wait(Main::stream_media())
	 * }
	 */
	
	Main::_connection_timer.expires_at(Main::_connection_timer.expires_at()
			+ boost::posix_time::seconds(Main::_delay));
	Main::_connection_timer.async_wait(boost::bind(&Main::runConnection, this));
}

void Main::runInterface()
{
	Main::_interface->update();
	
	Main::_interface_timer.expires_at(Main::_interface_timer.expires_at()
			+ boost::posix_time::seconds(Main::_delay));
	Main::_interface_timer.async_wait(boost::bind(&Main::runInterface, this));
}



int main()
{
	boost::asio::io_service io;
	Main root(io);
	io.run();
}
