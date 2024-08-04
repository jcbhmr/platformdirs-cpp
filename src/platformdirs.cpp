#include "platformdirs.h"
#include <filesystem>
#include <string>
#include <fmt/format.h>

std::string platformdirs::user_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming, bool ensure_exists) {
    return platformdirs::api::platform_dirs(appname, appauthor, version, roaming, false, true, ensure_exists).user_data_dir();
}

std::string platformdirs::site_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool multipath, bool ensure_exists) {
    return platformdirs::api::platform_dirs(appname, appauthor, version, false, multipath, true, ensure_exists).user_data_dir();
}
