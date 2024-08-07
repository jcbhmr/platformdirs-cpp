#pragma once
#undef unix
#include "api.h"
#include <filesystem>
#include <optional>
#include <string>
#include <variant>

namespace platformdirs {
namespace unix {

/**
 * On Unix/Linux, we follow the XDG Basedir Spec
 * https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html.
 *
 * The spec allows overriding directories with environment variables. The
 * examples shown are the default values, alongside the name of the environment
 * variable that overrides them. Makes use of the appname, version, multipath,
 * opinion, ensure_exists.
 */
class unix : public platformdirs::api::platform_dirs_abc {
public:
  unix(const std::optional<std::string> &appname = std::nullopt,
       const std::variant<std::string, std::nullopt_t, bool> &appauthor =
           std::nullopt,
       const std::optional<std::string> &version = std::nullopt,
       bool roaming = false, bool multipath = false, bool opinion = true,
       bool ensure_exists = false);

  /** @return data directory tied to the user, e.g.
   * `~/.local/share/$appname/$version` or `$XDG_DATA_HOME/$appname/$version` */
  std::string user_data_dir() const override;

private:
  auto site_data_dirs() const -> std::vector<std::string>;

public:
  /**
   * @returns data directories shared by users (if multipath is
   * enabled and `XDG_DATA_DIRS` is set and a multi path the response is also a
   * multi path separated by the OS path separator), e.g.
   * `/usr/local/share/$appname/$version` or `/usr/share/$appname/$version`
   */
  std::string site_data_dir() const override;

  /** @return config directory tied to the user, e.g.
   * `~/.config/$appname/$version` or `$XDG_CONFIG_HOME/$appname/$version` */
  std::string user_config_dir() const override;

private:
  auto site_config_dirs() const -> std::vector<std::string>;

public:
  /** @return config directories shared by users (if multipath
   * is enabled and `XDG_CONFIG_DIRS` is set and a multi path the response is
   * also a multi path separated by the OS path separator), e.g.
   * `/etc/xdg/$appname/$version` */
  std::string site_config_dir() const override;

  /** @return cache directory tied to the user, e.g.
   * `~/.cache/$appname/$version` or
   * `~/$XDG_CACHE_HOME/$appname/$version` */
  std::string user_cache_dir() const override;

  /** @return cache directory shared by users, e.g.
   * `/var/cache/$appname/$version` */
  std::string site_cache_dir() const override;

  std::string user_state_dir() const override;

  std::string user_log_dir() const override;

  std::string user_documents_dir() const override;

  std::string user_downloads_dir() const override;

  std::string user_pictures_dir() const override;

  std::string user_videos_dir() const override;

  std::string user_music_dir() const override;

  std::string user_desktop_dir() const override;

  std::string user_runtime_dir() const override;

  std::string site_runtime_dir() const override;

  std::filesystem::path site_data_path() const override;

  std::filesystem::path site_config_path() const override;

  std::filesystem::path site_cache_path() const override;

private:
  std::filesystem::path
  first_item_as_path_if_multipath(const std::string &directory) const;
};

} // namespace unix
} // namespace platformdirs
