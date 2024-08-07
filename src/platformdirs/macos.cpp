#include "macos.h"
#include "utils.h"
#include <filesystem>
#include <optional>
#include <string>
#include <variant>
#include <vector>

platformdirs::macos::macos::macos(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming, bool multipath,
    bool opinion, bool ensure_exists)
    : platformdirs::api::platform_dirs_abc(appname, appauthor, version, roaming,
                                           multipath, opinion, ensure_exists) {}

auto platformdirs::macos::macos::user_data_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Library/Application Support")
           .string()});
}

auto platformdirs::macos::macos::site_data_dir() const -> std::string {
  return "/Library/Application Support";
}

auto platformdirs::macos::macos::user_config_dir() const -> std::string {
  return this->user_data_dir();
}

auto platformdirs::macos::macos::site_config_dir() const -> std::string {
  return this->site_data_dir();
}

auto platformdirs::macos::macos::user_cache_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Library/Caches").string()});
}

auto platformdirs::macos::macos::site_cache_dir() const -> std::string {
  return "/Library/Caches";
}

auto platformdirs::macos::macos::user_state_dir() const -> std::string {
  return this->user_data_dir();
}

auto platformdirs::macos::macos::user_log_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Library/Logs").string()});
}

auto platformdirs::macos::macos::user_documents_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Documents").string()});
}

auto platformdirs::macos::macos::user_downloads_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Downloads").string()});
}

auto platformdirs::macos::macos::user_pictures_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Pictures").string()});
}

auto platformdirs::macos::macos::user_videos_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Movies").string()});
}

auto platformdirs::macos::macos::user_music_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Music").string()});
}

auto platformdirs::macos::macos::user_desktop_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Desktop").string()});
}

auto platformdirs::macos::macos::user_runtime_dir() const -> std::string {
  return this->append_app_name_and_version(
      {(platformdirs::utils::home_path() / "Library/Caches/TemporaryItems")
           .string()});
}

auto platformdirs::macos::macos::site_runtime_dir() const -> std::string {
  return this->user_runtime_dir();
}
