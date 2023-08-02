#include <exception>
#include <thread>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "server.h"
#include "sockpp/tcp_acceptor.h"

struct Request {
    std::string type;
    std::string path;
    std::string protocol;
};

struct Response {
    std::string protocol;
    std::string statusCode;
    std::string statusText;
    std::unordered_map<std::string, std::string> headers;
    std::string content;
};

// Sanitize the string by replacing .. with __
std::string Sanitize(std::string str) {
    size_t index = 0;
    while (true) {
        index = str.find("..", index);
        if (index == std::string::npos) break;

        str.replace(index, 2, "__");

        index += 2;
    }
    return str;
}

Request ParseRequest(std::string requestText) {
    // Parse the status line of the HTTP request (e.g GET / HTTP/1.1)
    // This is a pretty spaghetti implementation but it works

    Request request;
    std::size_t pos = requestText.find("\r\n");
    std::string statusLine = requestText.substr(0, pos);
    std::istringstream ss(requestText);
    std::string temp;
    std::vector<std::string> statusVector;
    while (std::getline(ss, temp, ' ')) {
        statusVector.push_back(temp);
    }
    request.type = statusVector[0];
    request.path = Sanitize(statusVector[1]);
    request.protocol = statusVector[2];
    return request;
}

std::string ConstructResponse(Response &response) {
    std::stringstream ss;
    ss << response.protocol << " " << response.statusCode << " " << response.statusText << "\r\n";
    for(std::unordered_map<std::string,std::string>::iterator it = response.headers.begin(); it !=  response.headers.end(); ++it) {
        ss << it->first << ": " << it->second << "\r\n";
    }
    ss << "\r\n";
    ss << response.content;
    return ss.str();
}

void HandleRequest(sockpp::tcp_socket sock, std::string path) {
    char buf[BUFFER_SIZE];
    ssize_t n;
    while((n = sock.read(buf, sizeof(buf))) > 0) {
        std::cout << "Responding...\n";
        Request request = ParseRequest(std::string(buf, n));
        if (request.path == "/") {
            request.path = "/index.html";
        }
        std::ifstream file(path + request.path);
        std::string statusCode = "200";
        std::string statusText = "OK";
        std::string fileText;
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            fileText = buffer.str();
            file.close();
        } else {
            statusCode = "404";
            statusText = "Not Found";
            fileText = "404 Not Found";
        }

        Response response;
        response.protocol = "HTTP/1.1";
        response.statusCode = statusCode;
        response.statusText = statusText;
        response.headers["X-Powered-By"] = "SHTTP";
        response.content = fileText;

        sock.write(ConstructResponse(response));
        sock.close();
    }
};

void HTTPServer::Serve(std::string path) {
    m_path = path;
}

void HTTPServer::Listen(int16_t port) {
    sockpp::initialize();
    sockpp::tcp_acceptor acc(port);
    if (!acc) throw std::runtime_error("TCP Acceptor can not be created");
    while (m_running) {
        sockpp::tcp_socket sock = acc.accept();
        std::cout << "Sock accepted...\n";
        if (!sock) continue;
        std::thread thr(HandleRequest, std::move(sock), m_path);
        thr.detach();
    }   
}