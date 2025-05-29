#include "SimpleServer.hpp"

ZAI::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
	socket = new ListeningSocket(domain, service, protocol, 
			port, interface, bklg);
}

ZAI::ListeningSocket * ZAI::SimpleServer::get_socket()
{
	return socket;
}
