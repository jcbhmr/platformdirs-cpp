#pragma once
#undef unix
#include <filesystem>
#include <string>
#include <string_view>
#include "platformdirs/version.h"

#if __COSMOPOLITAN__
#include "platformdirs/cosmopolitan.h"
#include "platformdirs/macos.h"
#include "platformdirs/windows.h"
#include "platformdirs/unix.h"
#elif __APPLE__
#include "platformdirs/macos.h"
#elif _WIN32
#include "platformdirs/windows.h"
#else
#include "platformdirs/unix.h"
#endif

namespace platformdirs {

const auto& version_ = platformdirs::version::version;

const auto& version_tuple = platformdirs::version::version_tuple;

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

std::string user_data_dir();
std::string user_data_dir(const std::optional<std::string>& appname);
std::string user_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor);
std::string user_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version);
std::string user_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming);
std::string user_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming, bool ensure_exists);

std::string site_data_dir();
std::string site_data_dir(const std::optional<std::string>& appname);
std::string site_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor);
std::string site_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version);
std::string site_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming);
std::string site_data_dir(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming, bool ensure_exists);

std::string user_documents_dir();

std::string user_downloads_dir();

std::string user_pictures_dir();

std::filesystem::path user_data_path();
std::filesystem::path user_data_path(const std::optional<std::string>& appname);
std::filesystem::path user_data_path(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor);
std::filesystem::path user_data_path(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version);
std::filesystem::path user_data_path(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming);
std::filesystem::path user_data_path(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming, bool ensure_exists);

std::filesystem::path user_documents_path();

std::filesystem::path user_downloads_path();

} // namespace platformdirs
