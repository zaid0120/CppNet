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

	std::istringstream stream(buffer);
	std::string line;
	bool firstLine = true;

	while (std::getline(stream, line)) 
	{
		if (!line.empty() && line.back() == '\r') {
			line.pop_back();
		}

		if (firstLine) {
			firstLine = false;

			// First line like: GET /index.html HTTP/1.1
			std::istringstream firstLineStream(line);
			std::string method, path, version;
			firstLineStream >> method >> path >> version;

			if (method == "GET") {
				if (path == "/")
					requested_path = "./index.html";
				else
					requested_path = "." + path;
			}
		}

		if (line.find("Referer:") == 0) 
		{
			std::string referer = line.substr(8);
			referer.erase(0, referer.find_first_not_of(" \t"));

			std::size_t path_pos = referer.find('/', referer.find("://") + 3);
			if (path_pos != std::string::npos) {
				std::string referer_path = referer.substr(path_pos);
				std::cout << "Referer path: " << referer_path << '\n';
			}
		}
	}

	if (requested_path.empty()) {
		requested_path = "./index.html";
	}

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
	std::string content = get_file_content(requested_path);
	if (content.empty()) {
		std::cout << "❌ 404 Not Found: " << requested_path << std::endl;
		std::string not_found = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found";
		write(new_socket, not_found.c_str(), not_found.length());
	} else {
		std::cout << "✅ 200 OK: " << requested_path << std::endl;
		std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" + content;
		write(new_socket, response.c_str(), response.length());
	}
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

