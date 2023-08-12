#include <iostream>
#include "server.h"
#include "config.h"

int main() {
    HTTPServer server;
    Config config;
    
    switch (config.load_config())
    {
    case 1:
        std::cerr << "config.toml does not exist!\n. please put it where the binary is located.";
        return 1;
        break;
    
    case 2:
        std::cerr << "Config error: one of the properties required does not exist!";
        break;
    default:
        break;
    }

    server.Serve(config.serve);
    server.Listen(config.port);
    return 0;
}