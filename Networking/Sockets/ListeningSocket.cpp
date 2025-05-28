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
	listening = listen(get_connection(), backlog);
}
