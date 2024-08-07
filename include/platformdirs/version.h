#pragma once
#include <cstdint>
#include <string>
#include <tuple>

namespace platformdirs {
namespace version {

std::string version();

std::tuple<uint8_t, uint8_t, uint8_t> version_tuple();

} // namespace version
} // namespace platformdirs
