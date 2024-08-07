#pragma once
#undef unix
#include <optional>
#include <platformdirs/unix.h>

namespace platformdirs {
namespace unix {

auto get_user_media(const std::string &env_var,
                    const std::string &fallback_tilde_path) -> std::string;

auto get_user_dirs_folder(const std::string &key) -> std::optional<std::string>;

} // namespace unix
} // namespace platformdirs