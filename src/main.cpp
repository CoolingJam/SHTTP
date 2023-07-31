#include <iostream>
#include "server.h"
#include "config.h"

int main() {
    HTTPServer server;
    Config config;
    if (config.load_config() == 1) {
        std::cerr << "config.toml does not exist!\n. please put it where the binary is located.";
        return 1;
    }
    server.Serve("./www/");
    server.Listen(config.port);
    return 0;
}