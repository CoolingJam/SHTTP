#include <exception>
#include <thread>
#include "server.h"
#include "sockpp/tcp_acceptor.h"

void HandleRequest(sockpp::tcp_socket sock) {
    char buf[BUFFER_SIZE];
    ssize_t n;
    while((n = sock.read(buf, sizeof(buf))) > 0) {
        std::cout << "Responding...\n";
        sock.write("HTTP/1.1 200 OK\r\nContent-Length: 12\r\nContent-Type: text/plain\r\n\r\nHello World\n");
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
        std::thread thr(HandleRequest, std::move(sock));
        thr.detach();
    }
}