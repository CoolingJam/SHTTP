#include <string>

class HTTPServer {
    public:
    int Serve(std::string path);
    int Listen(int16_t port);
};