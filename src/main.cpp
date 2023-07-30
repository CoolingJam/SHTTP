#include <iostream>
#include "server.h"

int main() {
    HTTPServer server;
    server.Serve("./www/");
    server.Listen(8080);
}