//this class implements a call to the bind() function of 
// sockets as a definition of the connect_to_network 
// virtual function from simple socket.

#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace ZAI
{
class BindingSocket: public SimpleSocket
{
public:
	// Constructor	
	BindingSocket(int domain, int service, int protocol, 
			int port, u_long interface);
	// Virtual Function from parent
	int connect_to_network(int sock, struct sockaddr_in address);

};

}

#endif /* BindingSocket_hpp  */
