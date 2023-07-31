#include <stdint.h>

struct Config {
    uint16_t port;

    /**
     * Try to load config
     * @returns `0` if config was loaded
     * @returns `1` if there was an error.
     */
    int load_config();
};