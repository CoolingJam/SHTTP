#include "config.h"
#include "toml.hpp"

int Config::load_config() {
    try {
        auto data = toml::parse("config.toml");
        try {
            this->port = toml::find<uint16_t>(data, "port");
            this->serve = toml::find<std::string>(data, "serve");
        } catch (std::runtime_error err) {
            return 2;
        }
    } catch (std::runtime_error err) {
        return 1;
    }
    return 0;
};