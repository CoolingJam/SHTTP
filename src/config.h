#include <stdint.h>
#include <string>

struct Config {
    uint16_t port;
    std::string serve;

    /**
     * Try to load config
     * @returns `0` if config was loaded
     * @returns `1` if there was an error.
     */
    int load_config();
};