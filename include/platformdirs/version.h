#pragma once
#include <tuple>
#include <cstdint>

namespace platformdirs {
namespace version {

const std::string version();

const std::tuple<uint8_t, uint8_t, uint8_t> version_tuple();

} // namespace version
} // namespace platformdirs
