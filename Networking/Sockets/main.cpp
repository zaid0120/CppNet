#include "ListeningSocket.hpp"

int main() {
	std::cout << "Starting ..." << std::endl;
	std::cout << "Binding Socket ..." << std::endl;
	ZAI::BindingSocket bs = ZAI::BindingSocket(AF_INET,
						   SOCK_STREAM,
						   0,
						   81,
						   INADDR_ANY);


	std::cout << "Listening Socket ..." << std::endl;
	ZAI::ListeningSocket ls = ZAI::ListeningSocket(AF_INET,
						   SOCK_STREAM,
						   0,
						   80,
						   INADDR_ANY,
						   10);

	std::cout << "Success!!" << std::endl;
}
