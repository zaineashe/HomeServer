#ifndef _MAIN_H_
#define	_MAIN_H_

#include "libraries.h"
#include "connection.h"
#include "interface.h"

class Main
{
public:
	Main();
	
private:
	Connection 	_connection;
	Interface 	_interface;
};

#endif // _MAIN_H_