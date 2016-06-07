#ifndef 	_MAIN_H_
#define		_MAIN_H_

#include "library.h"
#include "GUI.h"
#include "Server.h"

class Main
{
public:
	Main();
	~Main();
	
private:
	GUI 		_gui;
	Server		_server;
};


#endif	//	_MAIN_H_