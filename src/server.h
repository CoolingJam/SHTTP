#include <string>

#define BUFFER_SIZE 4096

class HTTPServer {
    public:
    void Serve(std::string path);
    void Listen(int16_t port);
    private:
    bool m_running = true;
    std::string m_path;
};