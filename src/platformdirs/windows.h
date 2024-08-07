#pragma once
#include <platformdirs/windows.h>

namespace platformdirs {
namespace windows {

auto get_win_folder_from_env_vars(const std::string &csidl_name) -> std::string;

auto get_win_folder_if_csidl_name_not_env_var(const std::string &csidl_name)
    -> std::optional<std::string>;

constexpr auto &get_win_folder = get_win_folder_from_env_vars;

} // namespace windows
} // namespace platformdirs
