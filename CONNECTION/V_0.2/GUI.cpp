#include "GUI.h"

GUI::GUI()
{
	LOG("Initilising Graphical User Interface");
}

GUI::~GUI()
{
	LOG("Terminating Graphical User Interface");
}


void GUI::start()
{
	LOG("Initilising GUI communication");
	while (true)
	{
		GUI::updateScreen();
		WAIT(GUI::_DELAY_);
	}
}

void GUI::updateScreen()
{
	LOG("Updating GUI Screen");
}