#include <iostream>
#include "server.h"
#include "config.h"

int main() {
    HTTPServer server;
    server.Serve("./www/");
    server.Listen(8080);
    if (config::load_config() == -1) {
        std::cerr << "config.toml does not exist!\n. please put it where the binary is located.";
        return -1;
    }

    std::cout << "Port: " << config::port << "\n";

    return 0;
}