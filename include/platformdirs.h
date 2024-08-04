#pragma once
#undef unix
#include <filesystem>
#include <string>
#include <string_view>
#include "platformdirs/version.h"

#if __COSMOPOLITAN__
#include "platformdirs/cosmopolitan.h"
#elif __APPLE__
#include "platformdirs/macos.h"
#elif _WIN32
#include "platformdirs/windows.h"
#else
#include "platformdirs/unix.h"
#endif

namespace platformdirs {

using version_ = platformdirs::version::version;

using platformdirs::version::version_tuple;

using platform_dirs = 
#if __COSMOPOLITAN__
platformdirs::cosmopolitan::cosmopolitan;
#elif __APPLE__
platformdirs::macos::macos;
#elif _WIN32
platformdirs::windows::windows;
#else
platformdirs::unix::unix;
#endif

using app_dirs = platform_dirs;

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data directory tied to the user
 */
std::string user_data_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns data directory shared by users
 */
std::string site_data_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config directory tied to the user
 */
std::string user_config_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns config directory shared by users
 */
std::string site_config_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool multipath = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param roaming See platform_dirs_abc::roaming
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache directory tied to the user
 */
std::string user_cache_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool ensure_exists = false);

/**
 * @param appname See platform_dirs_abc::appname
 * @param appauthor See platform_dirs_abc::appauthor
 * @param version See platform_dirs_abc::version
 * @param multipath See platform_dirs_abc::multipath
 * @param ensure_exists See platform_dirs_abc::ensure_exists
 * @returns cache directory shared by users
 */
std::string site_cache_dir(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool multipath = false, bool ensure_exists = false);

std::string user_documents_dir();

std::string user_downloads_dir();

std::string user_pictures_dir();

std::filesystem::path user_data_path();

std::filesystem::path user_documents_path();

std::filesystem::path user_downloads_path();

} // namespace platformdirs
