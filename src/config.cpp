#include "config.h"
#include "toml.hpp"

int Config::load_config() {
    try {
        auto data = toml::parse("config.toml");
        this->port = toml::find<uint16_t>(data, "port");
    } catch (std::runtime_error err) {
        return 1;
    }
    return 0;
};