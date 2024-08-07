#undef unix
#include "platformdirs.h"
#include <filesystem>
#include <fmt/format.h>
#include <memory>
#include <string>

std::string platformdirs::user_data_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_data_dir();
}

std::string platformdirs::site_data_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_data_dir();
}

std::string platformdirs::user_config_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_config_dir();
}

std::string platformdirs::site_config_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_config_dir();
}

std::string platformdirs::user_cache_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_cache_dir();
}

std::string platformdirs::site_cache_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_cache_dir();
}

std::string platformdirs::user_state_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_state_dir();
}

std::string platformdirs::user_log_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_log_dir();
}

std::string platformdirs::user_documents_dir() {
  return platformdirs::platform_dirs().user_documents_dir();
}

std::string platformdirs::user_downloads_dir() {
  return platformdirs::platform_dirs().user_downloads_dir();
}

std::string platformdirs::user_pictures_dir() {
  return platformdirs::platform_dirs().user_pictures_dir();
}

std::string platformdirs::user_videos_dir() {
  return platformdirs::platform_dirs().user_videos_dir();
}

std::string platformdirs::user_music_dir() {
  return platformdirs::platform_dirs().user_music_dir();
}

std::string platformdirs::user_desktop_dir() {
  return platformdirs::platform_dirs().user_desktop_dir();
}

std::string platformdirs::user_runtime_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_runtime_dir();
}

std::string platformdirs::site_runtime_dir(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_runtime_dir();
}

std::filesystem::path platformdirs::user_data_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_data_path();
}

std::filesystem::path platformdirs::site_data_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_data_path();
}

std::filesystem::path platformdirs::user_config_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_config_path();
}

std::filesystem::path platformdirs::site_config_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_config_path();
}

std::filesystem::path platformdirs::user_cache_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_cache_path();
}

std::filesystem::path platformdirs::site_cache_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_cache_path();
}

std::filesystem::path platformdirs::user_state_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_state_path();
}

std::filesystem::path platformdirs::user_log_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_log_path();
}

std::filesystem::path platformdirs::user_documents_path() {
  return platformdirs::platform_dirs().user_documents_path();
}

std::filesystem::path platformdirs::user_downloads_path() {
  return platformdirs::platform_dirs().user_downloads_path();
}

std::filesystem::path platformdirs::user_pictures_path() {
  return platformdirs::platform_dirs().user_pictures_path();
}

std::filesystem::path platformdirs::user_videos_path() {
  return platformdirs::platform_dirs().user_videos_path();
}

std::filesystem::path platformdirs::user_music_path() {
  return platformdirs::platform_dirs().user_music_path();
}

std::filesystem::path platformdirs::user_desktop_path() {
  return platformdirs::platform_dirs().user_desktop_path();
}

std::filesystem::path platformdirs::user_runtime_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, roaming,
                                     false, true, ensure_exists)
      .user_runtime_path();
}

std::filesystem::path platformdirs::site_runtime_path(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool multipath,
    bool ensure_exists) {
  return platformdirs::platform_dirs(appname, appauthor, version, false,
                                     multipath, true, ensure_exists)
      .site_runtime_path();
}
