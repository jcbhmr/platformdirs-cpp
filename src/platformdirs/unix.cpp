#undef unix
#include "unix.h"
#include <cstdlib>
#include <filesystem>
#include <optional>
#include <string>
#include <variant>
#if !_WIN32
#include <unistd.h>
#endif
#if __COSMOPOLITAN__
#include <cosmo.h>
#endif
#include "utils.h"

platformdirs::unix::unix::unix(
    const std::optional<std::string> &appname,
    const std::variant<std::string, std::nullopt_t, bool> &appauthor,
    const std::optional<std::string> &version, bool roaming, bool multipath,
    bool opinion, bool ensure_exists)
    : platformdirs::api::platform_dirs_abc(appname, appauthor, version, roaming,
                                           multipath, opinion, ensure_exists) {}

std::string platformdirs::unix::unix::user_data_dir() const {
  auto path_c_str = std::getenv("XDG_DATA_HOME");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = (platformdirs::utils::home_path() / ".local/share").string();
  }
  return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::site_data_dirs() const
    -> std::vector<std::string> {
  auto path_c_str = std::getenv("XDG_DATA_DIRS");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = std::string("/usr/local/share") + platformdirs::utils::pathsep() +
           "/usr/share";
  }
  auto appended = std::vector<std::string>();
  for (auto p :
       platformdirs::utils::split(path, platformdirs::utils::pathsep())) {
    appended.push_back(this->append_app_name_and_version({p}));
  }
  return appended;
}

std::string platformdirs::unix::unix::site_data_dir() const {
  auto const dirs = this->site_data_dirs();
  if (!this->multipath) {
    return dirs.at(0);
  }
  return platformdirs::utils::join(dirs, platformdirs::utils::pathsep());
}

auto platformdirs::unix::unix::user_config_dir() const -> std::string {
  auto path_c_str = std::getenv("XDG_CONFIG_HOME");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = (platformdirs::utils::home_path() / ".config").string();
  }
  return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::site_config_dirs() const
    -> std::vector<std::string> {
  auto path_c_str = std::getenv("XDG_CONFIG_DIRS");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = "/etc/xdg";
  }
  auto appended = std::vector<std::string>();
  for (auto p :
       platformdirs::utils::split(path, platformdirs::utils::pathsep())) {
    appended.push_back(this->append_app_name_and_version({p}));
  }
  return appended;
}

std::string platformdirs::unix::unix::site_config_dir() const {
  auto const dirs = this->site_config_dirs();
  if (!this->multipath) {
    return dirs.at(0);
  }
  return platformdirs::utils::join(dirs, platformdirs::utils::pathsep());
}

auto platformdirs::unix::unix::user_cache_dir() const -> std::string {
  auto path_c_str = std::getenv("XDG_CACHE_HOME");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = (platformdirs::utils::home_path() / ".cache").string();
  }
  return this->append_app_name_and_version({path});
}

std::string platformdirs::unix::unix::site_cache_dir() const {
  return this->append_app_name_and_version({"/var/cache"});
}

auto platformdirs::unix::unix::user_state_dir() const -> std::string {
  auto path_c_str = std::getenv("XDG_STATE_HOME");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
    path = (platformdirs::utils::home_path() / ".local/state").string();
  }
  return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::user_log_dir() const -> std::string {
  auto path = this->user_state_dir();
  if (this->opinion) {
    path = (std::filesystem::path(path) / "log").string();
    this->optionally_create_directory(path);
  }
  return path;
}

auto platformdirs::unix::unix::user_documents_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_DOCUMENTS_DIR", "Documents");
}

auto platformdirs::unix::unix::user_downloads_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_DOWNLOAD_DIR", "Downloads");
}

auto platformdirs::unix::unix::user_pictures_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_PICTURES_DIR", "Pictures");
}

auto platformdirs::unix::unix::user_videos_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_VIDEOS_DIR", "Videos");
}

auto platformdirs::unix::unix::user_music_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_MUSIC_DIR", "Music");
}

auto platformdirs::unix::unix::user_desktop_dir() const -> std::string {
  return platformdirs::unix::get_user_media("XDG_DESKTOP_DIR", "Desktop");
}

auto platformdirs::unix::unix::user_runtime_dir() const -> std::string {
  auto path_c_str = std::getenv("XDG_RUNTIME_DIR");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
#if __COSMOPOLITAN__
    if (IsFreebsd()) {
      path = (std::filesystem::path("/var/run/user") / std::to_string(getuid()))
                 .string();
      if (!std::filesystem::exists(path)) {
        path = std::string("/tmp/runtime-") + std::to_string(getuid());
      }
    } else {
      path = std::string("/run/user/") + std::to_string(getuid());
    }
#elif BSD
    path = (std::filesystem::path("/var/run/user") / std::to_string(getuid()))
               .string();
    if (!std::filesystem::exists(path)) {
      path = std::string("/tmp/runtime-") + std::to_string(getuid());
    }
#elif _WIN32
    throw std::runtime_error(
        "getuid() equivalent for windows not implemented yet");
#else
    path = std::string("/run/user/") + std::to_string(getuid());
#endif
  }
  return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::site_runtime_dir() const -> std::string {
  auto path_c_str = std::getenv("XDG_RUNTIME_DIR");
  auto path = path_c_str ? std::string(path_c_str) : std::string();
  platformdirs::utils::ltrim(path);
  platformdirs::utils::rtrim(path);
  if (path == "") {
#if __COSMOPOLITAN__
    if (IsFreebsd()) {
      path = "/var/run";
    } else {
      path = "/run";
    }
#elif BSD
    path = "/var/run";
#else
    path = "/run";
#endif
  }
  return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::site_data_path() const -> std::filesystem::path {
  return this->first_item_as_path_if_multipath(this->site_data_dir());
}

auto platformdirs::unix::unix::site_config_path() const
    -> std::filesystem::path {
  return this->first_item_as_path_if_multipath(this->site_config_dir());
}

auto platformdirs::unix::unix::site_cache_path() const
    -> std::filesystem::path {
  return this->first_item_as_path_if_multipath(this->site_cache_dir());
}

std::filesystem::path platformdirs::unix::unix::first_item_as_path_if_multipath(
    const std::string &directory) const {
  std::string dir2;
  if (this->multipath) {
    dir2 = platformdirs::utils::split(directory,
                                      platformdirs::utils::pathsep())[0];
  } else {
    dir2 = directory;
  }
  return std::filesystem::path(dir2);
}

auto platformdirs::unix::get_user_media(const std::string &env_var,
                                        const std::string &fallback_tilde_path)
    -> std::string {
  std::string media_dir;
  auto media_dir_opt = platformdirs::unix::get_user_dirs_folder(env_var);
  if (media_dir_opt) {
    media_dir = media_dir_opt.value();
  } else {
    auto media_dir_c_str = std::getenv(env_var.c_str());
    media_dir = media_dir_c_str ? std::string(media_dir_c_str) : std::string();
    platformdirs::utils::ltrim(media_dir);
    platformdirs::utils::rtrim(media_dir);
    if (media_dir == "") {
      media_dir =
          (platformdirs::utils::home_path() / fallback_tilde_path).string();
    }
  }
  return media_dir;
}

auto platformdirs::unix::get_user_dirs_folder(const std::string &key)
    -> std::optional<std::string> {
  auto user_dirs_config_path =
      std::filesystem::path(platformdirs::unix::unix().user_config_dir()) /
      "user-dirs.dirs";
  if (std::filesystem::exists(user_dirs_config_path)) {
    // TODO
    return std::nullopt;
  }
  return std::nullopt;
}
