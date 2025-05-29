#include "TestServer.hpp"

ZAI::TestServer::TestServer() : SimpleServer(AF_INET, 
						SOCK_STREAM, 
						0, 
						80, 
						INADDR_ANY, 
						10)
{
	launch();
}

void ZAI::TestServer::accepter()
{
	struct sockaddr_in address = get_socket()->get_address();
	int addrlen = sizeof(address);

	new_socket = accept(get_socket()->get_sock(), 
			    (struct sockaddr *)&address,
			    (socklen_t *)&addrlen);

	read(new_socket, buffer, 30000);

}

void ZAI::TestServer::handler()
{
	std::cout << buffer << std::endl;
}

std::string ZAI::TestServer::get_file_content(std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << path << 
		std::endl;

        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    return content;
}

void ZAI::TestServer::responder()
{
	std::string path = "./index.html";
	std::string hello = ZAI::TestServer::get_file_content(path);
	std::cout << hello << std::endl;
	write(new_socket, hello.c_str(), hello.length());
	close(new_socket);
}

void ZAI::TestServer::launch()
{
	while(true) 
	{
		std::cout << ".....WAITING....." << std::endl;
		accepter();
		handler();
		responder();
		std::cout << ".....DONE....." << std::endl;
	
	}

}

