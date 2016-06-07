#ifndef		_GUI_H_
#define		_GUI_H_

#include "library.h"

class GUI
{
public:
	GUI();
	~GUI();
	
	void start();
	void setMessage(std::string);
	
private:
//************ VARIABLES ************
	std::string 	_message;
	
//************ FUNCTIONS ************
	void updateScreen();
	
//************ CONSTANTS ************
	static const int _DELAY_ = 1;
};

#endif	//	_GUI_H_