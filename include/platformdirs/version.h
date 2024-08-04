#pragma once
#include <tuple>
#include <string>
#include <cstdint>

namespace platformdirs {
namespace version {

std::string version();

std::tuple<uint8_t, uint8_t, uint8_t> version_tuple();

} // namespace version
} // namespace platformdirs
