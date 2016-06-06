# Connection

This is the backend of the server, where C++ socket connections are being used.
Every file and byte is communicated from the users client device to this host machine using whats in this connections

This is where the program starts, it starts seperate threads to control connection to the client and running the interface at the same time.







# V_0.1

Attempt at making this base class structure with the threading outlined and everything mapped out

 - Problems
Too messy for the simplistic task
Could not make the tcp::acceptor() asynchronous in the un-encapsulated environment.
Did not use threads, just asynchronous waits, implementing threading for better results.
