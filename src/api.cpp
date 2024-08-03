#include "api.h"
#include <filesystem>
#include <string>
#include <string_view>
#include <optional>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include <cstdint>
#include <cstdlib>

namespace platformdirs {
namespace api {

platform_dirs_abc::platform_dirs_abc(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool multipath = false, bool opinion = true, bool ensure_exists = false) {
    this->appname = appname;
    this->appauthor = appauthor;
    this->version = version;
    this->roaming = roaming;
    this->multipath = multipath;
    this->opinion = opinion;
    this->ensure_exists = ensure_exists;
}

std::filesystem::path user_data_path() const {
    return std::filesystem::path(this->user_data_dir());
}

std::filesystem::path site_data_path() const {
    return std::filesystem::path(this->site_data_dir());
}

std::filesystem::path user_config_path() const {
    return std::filesystem::path(this->user_config_dir());
}

std::filesystem::path site_config_path() const {
    return std::filesystem::path(this->site_config_dir());
}

std::filesystem::path user_cache_path() const {
    return std::filesystem::path(this->user_cache_dir());
}

std::filesystem::path site_cache_path() const {
    return std::filesystem::path(this->site_cache_dir());
}

std::filesystem::path user_state_path() const {
    return std::filesystem::path(this->user_state_dir());
}

std::filesystem::path user_log_path() const {
    return std::filesystem::path(this->user_log_dir());
}

std::filesystem::path user_documents_path() const {
    return std::filesystem::path(this->user_documents_dir());
}

std::filesystem::path user_downloads_path() const {
    return std::filesystem::path(this->user_downloads_dir());
}

std::filesystem::path user_pictures_path() const {
    return std::filesystem::path(this->user_pictures_dir());
}

std::filesystem::path user_videos_path() const {
    return std::filesystem::path(this->user_videos_dir());
}

std::filesystem::path user_music_path() const {
    return std::filesystem::path(this->user_music_dir());
}

std::filesystem::path user_desktop_path() const {
    return std::filesystem::path(this->user_desktop_dir());
}

std::filesystem::path user_runtime_path() const {
    return std::filesystem::path(this->user_runtime_dir());
}

std::filesystem::path site_runtime_path() const {
    return std::filesystem::path(this->site_runtime_dir());
}

} // namespace api
} // namespace platformdirs