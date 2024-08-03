#pragma once
#include <filesystem>
#include <string>
#include <string_view>

namespace platformdirs {
namespace api {

class platform_dirs_abc {
public:
std::optional<std::string> appname;
std::variant<std::string, std::nullopt_t, bool> appauthor;
std::optional<std::string> version;
bool roaming;
bool multipath;
bool opinion;
bool ensure_exists;

platform_dirs_abc(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool multipath = false, bool opinion = true, bool ensure_exists = false);

virtual std::string user_data_dir() const;

virtual std::string site_data_dir() const;

virtual std::string user_config_dir() const;

virtual std::string site_config_dir() const;

virtual std::string user_cache_dir() const;

virtual std::string site_cache_dir() const;

virtual std::string user_state_dir() const;

virtual std::string user_log_dir() const;

virtual std::string user_documents_dir() const;

virtual std::string user_downloads_dir() const;

virtual std::string user_pictures_dir() const;

virtual std::string user_videos_dir() const;

virtual std::string user_music_dir() const;

virtual std::string user_desktop_dir() const;

virtual std::string user_runtime_dir() const;

virtual std::string site_runtime_dir() const;

std::filesystem::path user_data_path() const;

std::filesystem::path site_data_path() const;

std::filesystem::path user_config_path() const;

std::filesystem::path site_config_path() const;

std::filesystem::path user_cache_path() const;

std::filesystem::path site_cache_path() const;

std::filesystem::path user_state_path() const;

std::filesystem::path user_log_path() const;

std::filesystem::path user_documents_path() const;

std::filesystem::path user_downloads_path() const;

std::filesystem::path user_pictures_path() const;

std::filesystem::path user_videos_path() const;

std::filesystem::path user_music_path() const;

std::filesystem::path user_desktop_path() const;

std::filesystem::path user_runtime_path() const;

std::filesystem::path site_runtime_path() const;

}

} // namespace api
} // namespace platformdirs