THIS PROGRAM IS WHAT WILL BE RUN ON THE CLIENT COMPUTER
IT WILL TRY TO CONNECT TO THE HOST MACHINE TO STREAM
ALSO HAVE A GUI INTERFACE

**NOTES**
Interface
	- Use a python interface for the GUI
	- To use python, the program must include python in the programs files

Main Control
	- Control everything from a main executable
	- Will have to be written in C++ / Objective-C dependent on the OS
	- It will run the interface on seperate thread
	- Wait for interface to write to a registry file
	- Then start sending to host machine
