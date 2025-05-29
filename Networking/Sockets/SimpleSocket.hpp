/*
    Header file for the socket object.
    Author: Zaid Ali
    File: SimpleSocket.hpp
*/

#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace ZAI 
{
class SimpleSocket 
{
private:
	struct sockaddr_in address;
	int sock;
	int connection;
public:
	// Constructor
	SimpleSocket(int domain, int service, int protocol, 
			int port, u_long interface);
	// Virtual Function to connect to network
	virtual int connect_to_network(int sock, 
			struct sockaddr_in address) = 0;
	// Function to test sockets and connections
	void test_connection(int);
	// Getter Functions
	struct sockaddr_in get_address();
	int get_sock();
	int get_connection();
	// Setter Functions
	void set_connection(int con);
};
}


#endif /* SimpleSocket_hpp  */

