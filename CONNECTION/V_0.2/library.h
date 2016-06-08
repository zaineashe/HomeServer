#ifndef 	_LIBRARY_H_
#define		_LIBRARY_H_

#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/asio/streambuf.hpp>

#define _LOG_

//************ INLINE FUNCTIONS ************

void inline LOG (std::string message)
{
#ifdef _LOG_
	std::cout << message << std::endl;
#endif
}

void inline WAIT (int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
}


#endif	//	_LIBRARY_H_