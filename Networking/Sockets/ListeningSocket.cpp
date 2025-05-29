#include "ListeningSocket.hpp"

ZAI::ListeningSocket::ListeningSocket(int domain, int service, 
		int protocol, int port, u_long interface, int bklg):
       		BindingSocket(domain, service, protocol, port,
			      interface)
{
	backlog = bklg;
	start_listening();
	test_connection(listening);


}

void ZAI::ListeningSocket::start_listening()
{
	listening = listen(get_sock(), backlog);
}

//getters

int ZAI::ListeningSocket::get_listening()
{
	return listening;
}

int ZAI::ListeningSocket::get_backlog()
{
	return backlog;
}

