#include <stdint.h>
#include "toml.hpp"

namespace config {
    uint16_t port;

    /**
     * Try to load config
     * @returns `0` if config was loaded
     * @returns `-1` if there was an error.
     */
    int load_config() {
        try {
            auto data = toml::parse("config.toml");
            config::port = toml::find<uint16_t>(data, "port");
        } catch (std::runtime_error err) {
            return -1;
        }
        return 0;
    };

} // namespace Config