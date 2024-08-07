#include "windows.h"
#include "utils.h"
#include <filesystem>
#include <fmt/format.h>
#include <optional>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

platformdirs::windows::windows::windows(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming, bool multipath,
    bool opinion, bool ensure_exists)
    : platformdirs::api::platform_dirs_abc(appname, appauthor, version, roaming,
                                           multipath, opinion, ensure_exists) {}

auto platformdirs::windows::windows::user_data_dir() const -> std::string {
  auto const c = this->roaming ? std::string("CSIDL_APPDATA")
                               : std::string("CSIDL_LOCAL_APPDATA");
  auto const path = platformdirs::windows::get_win_folder(c);
  return this->append_parts(path);
}

auto platformdirs::windows::windows::append_parts(
    const std::string &path,
    const platformdirs::windows::windows::append_parts_options &options) const
    -> std::string {
  auto params = std::vector<std::string>();
  if (this->appname) {
    std::visit(
        [&params, this](auto &&arg) {
          using T = std::decay_t<decltype(arg)>;
          if constexpr (std::is_same_v<T, std::string>) {
            params.push_back(arg);
          } else if constexpr (std::is_same_v<T, std::nullopt_t>) {
            params.push_back(this->appname.value());
          } else if constexpr (std::is_same_v<T, bool>) {
            if (arg) {
              throw std::logic_error("this->appauthor bool must not be true");
            }
            // Skip when false.
          }
        },
        this->appauthor);
    params.push_back(this->appname.value());
    if (options.opinion_value && this->opinion) {
      params.push_back(options.opinion_value.value());
    }
    if (this->version) {
      params.push_back(this->version.value());
    }
  }
  auto path2 = std::filesystem::path(path);
  for (auto const p : params) {
    path2 = path2 / p;
  }
  this->optionally_create_directory(path2.string());
  return path2.string();
}

auto platformdirs::windows::windows::site_data_dir() const -> std::string {
  auto const path =
      platformdirs::windows::get_win_folder("CSIDL_COMMON_APPDATA");
  return this->append_parts(path);
}

auto platformdirs::windows::windows::user_config_dir() const -> std::string {
  return this->user_data_dir();
}

auto platformdirs::windows::windows::site_config_dir() const -> std::string {
  return this->site_data_dir();
}

auto platformdirs::windows::windows::user_cache_dir() const -> std::string {
  auto const path =
      platformdirs::windows::get_win_folder("CSIDL_LOCAL_APPDATA");
  return this->append_parts(path, {.opinion_value = "Cache"});
}

auto platformdirs::windows::windows::site_cache_dir() const -> std::string {
  auto const path =
      platformdirs::windows::get_win_folder("CSIDL_COMMON_APPDATA");
  return this->append_parts(path, {.opinion_value = "Cache"});
}

auto platformdirs::windows::windows::user_state_dir() const -> std::string {
  return this->user_data_dir();
}

auto platformdirs::windows::windows::user_log_dir() const -> std::string {
  auto path = this->user_data_dir();
  if (this->opinion) {
    path = (std::filesystem::path(path) / "Logs").string();
    this->optionally_create_directory(path);
  }
  return path;
}

auto platformdirs::windows::windows::user_documents_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_PERSONAL");
}

auto platformdirs::windows::windows::user_downloads_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_DOWNLOADS");
}

auto platformdirs::windows::windows::user_pictures_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_MYPICTURES");
}

auto platformdirs::windows::windows::user_videos_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_MYVIDEO");
}

auto platformdirs::windows::windows::user_music_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_MYMUSIC");
}

auto platformdirs::windows::windows::user_desktop_dir() const -> std::string {
  return platformdirs::windows::get_win_folder("CSIDL_DESKTOP_DIRECTORY");
}

auto platformdirs::windows::windows::user_runtime_dir() const -> std::string {
  auto const path =
      (std::filesystem::path(
           platformdirs::windows::get_win_folder("CSIDL_LOCAL_APPDATA")) /
       "Temp")
          .string();
  return this->append_parts(path);
}

auto platformdirs::windows::windows::site_runtime_dir() const -> std::string {
  return this->user_runtime_dir();
}

auto platformdirs::windows::get_win_folder_from_env_vars(
    const std::string &csidl_name) -> std::string {
  auto result = platformdirs::windows::get_win_folder_if_csidl_name_not_env_var(
      csidl_name);
  if (result) {
    return result.value();
  }

  std::string env_var_name;
  if (csidl_name == "CSIDL_APPDATA") {
    env_var_name = "APPDATA";
  } else if (csidl_name == "CSIDL_COMMON_APPDATA") {
    env_var_name = "ALLUSERSPROFILE";
  } else if (csidl_name == "CSIDL_LOCAL_APPDATA") {
    env_var_name = "LOCALAPPDATA";
  } else {
    throw std::runtime_error(fmt::format("Unknown CSIDL name: {}", csidl_name));
  }

  auto result_c_str = std::getenv(env_var_name.c_str());
  if (!result_c_str) {
    throw std::runtime_error(
        fmt::format("Unset environment variable: {}", env_var_name));
  }
  return std::string(result_c_str);
}

auto platformdirs::windows::get_win_folder_if_csidl_name_not_env_var(
    const std::string &csidl_name) -> std::optional<std::string> {
  if (csidl_name == "CSIDL_PERSONAL") {
    return (std::filesystem::path(std::getenv("USERPROFILE")) / "Documents")
        .string();
  }
  if (csidl_name == "CSIDL_DOWNLOADS") {
    return (std::filesystem::path(std::getenv("USERPROFILE")) / "Downloads")
        .string();
  }
  if (csidl_name == "CSIDL_MYPICTURES") {
    return (std::filesystem::path(std::getenv("USERPROFILE")) / "Pictures")
        .string();
  }
  if (csidl_name == "CSIDL_MYVIDEO") {
    return (std::filesystem::path(std::getenv("USERPROFILE")) / "Videos")
        .string();
  }
  if (csidl_name == "CSIDL_MYMUSIC") {
    return (std::filesystem::path(std::getenv("USERPROFILE")) / "Music")
        .string();
  }
  return std::nullopt;
}
