#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>

#include "BindingSocket.hpp"

namespace ZAI
{
class ListeningSocket : public BindingSocket
{
private:
	int backlog;
	int listening;
public:
	ListeningSocket(int domain, int service, int protocol, 
			int port, u_long interface, int bklg);
	void start_listening();
	int get_backlog();
	int get_listening();

};

}

#endif /* ListeningSocket_hpp  */
