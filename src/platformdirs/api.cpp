#include "api.h"
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>

platformdirs::api::platform_dirs_abc::platform_dirs_abc(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming, bool multipath,
    bool opinion, bool ensure_exists) {
  this->appname = appname;
  this->appauthor = appauthor;
  this->version = version;
  this->roaming = roaming;
  this->multipath = multipath;
  this->opinion = opinion;
  this->ensure_exists = ensure_exists;
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_data_path() const {
  return std::filesystem::path(this->user_data_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::site_data_path() const {
  return std::filesystem::path(this->site_data_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_config_path() const {
  return std::filesystem::path(this->user_config_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::site_config_path() const {
  return std::filesystem::path(this->site_config_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_cache_path() const {
  return std::filesystem::path(this->user_cache_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::site_cache_path() const {
  return std::filesystem::path(this->site_cache_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_state_path() const {
  return std::filesystem::path(this->user_state_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_log_path() const {
  return std::filesystem::path(this->user_log_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_documents_path() const {
  return std::filesystem::path(this->user_documents_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_downloads_path() const {
  return std::filesystem::path(this->user_downloads_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_pictures_path() const {
  return std::filesystem::path(this->user_pictures_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_videos_path() const {
  return std::filesystem::path(this->user_videos_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_music_path() const {
  return std::filesystem::path(this->user_music_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_desktop_path() const {
  return std::filesystem::path(this->user_desktop_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::user_runtime_path() const {
  return std::filesystem::path(this->user_runtime_dir());
}

std::filesystem::path
platformdirs::api::platform_dirs_abc::site_runtime_path() const {
  return std::filesystem::path(this->site_runtime_dir());
}

auto platformdirs::api::platform_dirs_abc::append_app_name_and_version(
    const std::vector<std::string> &base) const -> std::string {
  auto params = std::vector<std::string>(base.cbegin() + 1, base.cend());
  if (this->appname) {
    params.push_back(this->appname.value());
    if (this->version) {
      params.push_back(this->version.value());
    }
  }
  auto path = std::filesystem::path(base.at(0));
  for (auto p : params) {
    path = path / p;
  }
  this->optionally_create_directory(path.string());
  return path.string();
}

auto platformdirs::api::platform_dirs_abc::optionally_create_directory(
    const std::string &path) const -> void {
  if (this->ensure_exists) {
    std::filesystem::create_directories(path);
  }
}
