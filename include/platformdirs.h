#pragma once

/*! \mainpage
 * <img onerror="location.replace('./namespaceplatformdirs.html')" src="x">
 */

#undef unix
#include "platformdirs/api.h"
#include "platformdirs/version.h"
#include <filesystem>
#include <string>
#include <string_view>
#include <variant>
#if __COSMOPOLITAN__
#include "platformdirs/macos.h"
#include "platformdirs/unix.h"
#include "platformdirs/windows.h"
#include <cosmo.h>
#elif __APPLE__
#include "platformdirs/macos.h"
#elif _WIN32
#include "platformdirs/windows.h"
#else
#include "platformdirs/unix.h"
#endif

namespace platformdirs {

/** Renamed slightly because there's a module name (namespace) and function name with the same "version" identifier. */
constexpr auto &version_ = platformdirs::version::version;

constexpr auto &version_info = platformdirs::version::version_tuple;

#if __COSMOPOLITAN__
/**
 * Newtype wrapper around std::variant<...> of the implementations. We can't
 * determine the operating system at compile-time since Cosmopolitan Libc
 * allows a single binary to run on a variety of platforms. Thus, we need to
 * choose the OS-specific implementation at runtime.
 */
class platform_dirs {
public:
  std::variant<platformdirs::windows::windows, platformdirs::macos::macos,
               platformdirs::unix::unix>
      value;

public:
  platform_dirs(const std::optional<std::string> &appname = std::nullopt,
                const std::variant<std::string, std::nullopt_t, bool>
                    &appauthor = std::nullopt,
                const std::optional<std::string> &version = std::nullopt,
                bool roaming = false, bool multipath = false,
                bool opinion = true, bool ensure_exists = false) {
    if (IsWindows()) {
      this->value =
          platformdirs::windows::windows(appname, appauthor, version, roaming,
                                         multipath, opinion, ensure_exists);
    } else if (IsXnu()) {
      this->value =
          platformdirs::macos::macos(appname, appauthor, version, roaming,
                                     multipath, opinion, ensure_exists);
    } else {
      this->value =
          platformdirs::unix::unix(appname, appauthor, version, roaming,
                                   multipath, opinion, ensure_exists);
    }
  }

  std::string user_data_dir() const {
    return std::visit([](auto &&arg) { return arg.user_data_dir(); },
                      this->value);
  }

  std::string site_data_dir() const {
    return std::visit([](auto &&arg) { return arg.site_data_dir(); },
                      this->value);
  }

  std::string user_config_dir() const {
    return std::visit([](auto &&arg) { return arg.user_config_dir(); },
                      this->value);
  }

  std::string site_config_dir() const {
    return std::visit([](auto &&arg) { return arg.site_config_dir(); },
                      this->value);
  }

  std::string user_cache_dir() const {
    return std::visit([](auto &&arg) { return arg.user_cache_dir(); },
                      this->value);
  }

  std::string site_cache_dir() const {
    return std::visit([](auto &&arg) { return arg.site_cache_dir(); },
                      this->value);
  }

  std::string user_state_dir() const {
    return std::visit([](auto &&arg) { return arg.user_state_dir(); },
                      this->value);
  }

  std::string user_log_dir() const {
    return std::visit([](auto &&arg) { return arg.user_log_dir(); },
                      this->value);
  }

  std::string user_documents_dir() const {
    return std::visit([](auto &&arg) { return arg.user_documents_dir(); },
                      this->value);
  }

  std::string user_downloads_dir() const {
    return std::visit([](auto &&arg) { return arg.user_downloads_dir(); },
                      this->value);
  }

  std::string user_pictures_dir() const {
    return std::visit([](auto &&arg) { return arg.user_pictures_dir(); },
                      this->value);
  }

  std::string user_videos_dir() const {
    return std::visit([](auto &&arg) { return arg.user_videos_dir(); },
                      this->value);
  }

  std::string user_music_dir() const {
    return std::visit([](auto &&arg) { return arg.user_music_dir(); },
                      this->value);
  }

  std::string user_desktop_dir() const {
    return std::visit([](auto &&arg) { return arg.user_desktop_dir(); },
                      this->value);
  }

  std::string user_runtime_dir() const {
    return std::visit([](auto &&arg) { return arg.user_runtime_dir(); },
                      this->value);
  }

  std::string site_runtime_dir() const {
    return std::visit([](auto &&arg) { return arg.site_runtime_dir(); },
                      this->value);
  }

  std::filesystem::path user_data_path() const {
    return std::visit([](auto &&arg) { return arg.user_data_path(); },
                      this->value);
  }

  std::filesystem::path site_data_path() const {
    return std::visit([](auto &&arg) { return arg.site_data_path(); },
                      this->value);
  }

  std::filesystem::path user_config_path() const {
    return std::visit([](auto &&arg) { return arg.user_config_path(); },
                      this->value);
  }

  std::filesystem::path site_config_path() const {
    return std::visit([](auto &&arg) { return arg.site_config_path(); },
                      this->value);
  }

  std::filesystem::path user_cache_path() const {
    return std::visit([](auto &&arg) { return arg.user_cache_path(); },
                      this->value);
  }

  std::filesystem::path site_cache_path() const {
    return std::visit([](auto &&arg) { return arg.site_cache_path(); },
                      this->value);
  }

  std::filesystem::path user_state_path() const {
    return std::visit([](auto &&arg) { return arg.user_state_path(); },
                      this->value);
  }

  std::filesystem::path user_log_path() const {
    return std::visit([](auto &&arg) { return arg.user_log_path(); },
                      this->value);
  }

  std::filesystem::path user_documents_path() const {
    return std::visit([](auto &&arg) { return arg.user_documents_path(); },
                      this->value);
  }

  std::filesystem::path user_downloads_path() const {
    return std::visit([](auto &&arg) { return arg.user_downloads_path(); },
                      this->value);
  }

  std::filesystem::path user_pictures_path() const {
    return std::visit([](auto &&arg) { return arg.user_pictures_path(); },
                      this->value);
  }

  std::filesystem::path user_videos_path() const {
    return std::visit([](auto &&arg) { return arg.user_videos_path(); },
                      this->value);
  }

  std::filesystem::path user_music_path() const {
    return std::visit([](auto &&arg) { return arg.user_music_path(); },
                      this->value);
  }

  std::filesystem::path user_desktop_path() const {
    return std::visit([](auto &&arg) { return arg.user_desktop_path(); },
                      this->value);
  }

  std::filesystem::path user_runtime_path() const {
    return std::visit([](auto &&arg) { return arg.user_runtime_path(); },
                      this->value);
  }

  std::filesystem::path site_runtime_path() const {
    return std::visit([](auto &&arg) { return arg.site_runtime_path(); },
                      this->value);
  }
};
#else
/** Alias the current concrete implementation chosen at compile-time. */
using platform_dirs = 
#if __APPLE__
platformdirs::macos::macos;
#elif _WIN32
platformdirs::windows::windows;
#else
platformdirs::unix::unix;
#endif
#endif

using app_dirs = platform_dirs;

using platform_dirs_abc = platformdirs::api::platform_dirs_abc;

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data directory tied to the user
 */
std::string
user_data_dir(const std::optional<std::string> &appname = std::nullopt,
              const std::variant<std::string, std::nullopt_t, bool> &appauthor =
                  std::nullopt,
              const std::optional<std::string> &version = std::nullopt,
              bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data directory shared by users
 */
std::string
site_data_dir(const std::optional<std::string> &appname = std::nullopt,
              const std::variant<std::string, std::nullopt_t, bool> &appauthor =
                  std::nullopt,
              const std::optional<std::string> &version = std::nullopt,
              bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config directory tied to the user
 */
std::string user_config_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config directory shared by users
 */
std::string site_config_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache directory tied to the user
 */
std::string user_cache_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache directory shared by users
 */
std::string site_cache_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns state directory tied to the user
 */
std::string user_state_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns log directory tied to the user
 */
std::string
user_log_dir(const std::optional<std::string> &appname = std::nullopt,
             const std::variant<std::string, std::nullopt_t, bool> &appauthor =
                 std::nullopt,
             const std::optional<std::string> &version = std::nullopt,
             bool roaming = false, bool ensure_exists = false);

/** @returns documents directory tied to the user */
std::string user_documents_dir();

/** @returns downloads directory tied to the user */
std::string user_downloads_dir();

/** @returns pictures directory tied to the user */
std::string user_pictures_dir();

/** @returns videos directory tied to the user */
std::string user_videos_dir();

/** @returns music directory tied to the user */
std::string user_music_dir();

/** @returns desktop directory tied to the user */
std::string user_desktop_dir();

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns runtime directory tied to the user
 */
std::string user_runtime_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns runtime directory shared by users
 */
std::string site_runtime_dir(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data path tied to the user
 */
std::filesystem::path user_data_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data directory shared by users
 */
std::filesystem::path site_data_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config path tied to the user
 */
std::filesystem::path user_config_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config directory shared by users
 */
std::filesystem::path site_config_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache path tied to the user
 */
std::filesystem::path user_cache_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache directory shared by users
 */
std::filesystem::path site_cache_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns state path tied to the user
 */
std::filesystem::path user_state_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns log path tied to the user
 */
std::filesystem::path
user_log_path(const std::optional<std::string> &appname = std::nullopt,
              const std::variant<std::string, std::nullopt_t, bool> &appauthor =
                  std::nullopt,
              const std::optional<std::string> &version = std::nullopt,
              bool roaming = false, bool ensure_exists = false);

/** @returns documents path tied to the user */
std::filesystem::path user_documents_path();

/** @returns downloads path tied to the user */
std::filesystem::path user_downloads_path();

/** @returns pictures path tied to the user */
std::filesystem::path user_pictures_path();

/** @returns videos path tied to the user */
std::filesystem::path user_videos_path();

/** @returns music path tied to the user */
std::filesystem::path user_music_path();

/** @returns desktop path tied to the user */
std::filesystem::path user_desktop_path();

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns runtime path tied to the user
 */
std::filesystem::path user_runtime_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns runtime directory shared by users
 */
std::filesystem::path site_runtime_path(
    const std::optional<std::string> &appname = std::nullopt,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor =
        std::nullopt,
    const std::optional<std::string> &version = std::nullopt,
    bool multipath = false, bool ensure_exists = false);

} // namespace platformdirs
