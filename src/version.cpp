#include <platformdirs/version.h>
#include <tuple>
#include <cstdint>
#include <string>

const std::string platformdirs::version::version() {
    static const auto value = std::string(PROJECT_VERSION);
    return value;
}

const std::tuple<uint8_t, uint8_t, uint8_t> platform_dirs::version::version_tuple() {
    static const auto value = std::make_tuple(PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    return value;
}
