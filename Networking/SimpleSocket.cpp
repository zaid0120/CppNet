/* 
    Program file for the socket object. 
    Author: Zaid Ali 
    File: SimpleSocket.cpp 
*/

#include "SimpleSocket.hpp"

// Default Constructor
ZAI::SimpleSocket::SimpleSocket(int domain, int service, int protocol,
		int port, u_long interface) 
{
	// Define address struct
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);
	// Establish socket and test
	sock = socket(domain, service, protocol);
	test_connection(sock);
	// Establish network connection
	connection = connect_to_network(sock, address);
	test_connection(connection);
}

// Test Connection Virtual Function
void ZAI::SimpleSocket::test_connection(int item_to_test)
{
	// Confirms if socket or connection has been properly established
	if (item_to_test < 0)
	{
		perror("Failed to connect...");
		exit(EXIT_FAILURE);
	}
}

// Getter Functions
struct sockaddr_in ZAI::SimpleSocket::get_address()
{
	return address;
}

int ZAI::SimpleSocket::get_sock()
{
	return sock;
}

int ZAI::SimpleSocket::get_connection()
{
	return connection;
}
