#include "version.h"
#include <tuple>
#include <cstdint>
#include <string>

std::string platformdirs::version::version() {
    return std::string(PROJECT_VERSION);
}

std::tuple<uint8_t, uint8_t, uint8_t> platformdirs::version::version_tuple() {
    return std::make_tuple(PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
}
