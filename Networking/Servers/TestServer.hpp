#ifndef TestServer_hpp
#define TestServer_hpp

#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <sstream>

#include "SimpleServer.hpp"

namespace ZAI
{
class TestServer: public SimpleServer
{
private:
	char buffer[30000] = {0};
	int new_socket;
	std::string requested_path;

	void accepter();
	void handler();
	void responder();
public:
	TestServer();
	void launch();
	std::string get_file_content(std::string& path);
};

}


#endif /* TestServer_hpp  */ 
