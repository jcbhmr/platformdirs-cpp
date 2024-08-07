#pragma once
#include <filesystem>
#include <optional>
#include <string>
#include <variant>
#include <vector>

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

  platform_dirs_abc(const std::optional<std::string> &appname = std::nullopt,
                    const std::variant<std::string, std::nullopt_t, bool>
                        &appauthor = std::nullopt,
                    const std::optional<std::string> &version = std::nullopt,
                    bool roaming = false, bool multipath = false,
                    bool opinion = true, bool ensure_exists = false);

protected:
  auto append_app_name_and_version(const std::vector<std::string> &base) const
      -> std::string;
  auto optionally_create_directory(const std::string &path) const -> void;

public:
  virtual std::string user_data_dir() const = 0;

  virtual std::string site_data_dir() const = 0;

  virtual std::string user_config_dir() const = 0;

  virtual std::string site_config_dir() const = 0;

  virtual std::string user_cache_dir() const = 0;

  virtual std::string site_cache_dir() const = 0;

  virtual std::string user_state_dir() const = 0;

  virtual std::string user_log_dir() const = 0;

  virtual std::string user_documents_dir() const = 0;

  virtual std::string user_downloads_dir() const = 0;

  virtual std::string user_pictures_dir() const = 0;

  virtual std::string user_videos_dir() const = 0;

  virtual std::string user_music_dir() const = 0;

  virtual std::string user_desktop_dir() const = 0;

  virtual std::string user_runtime_dir() const = 0;

  virtual std::string site_runtime_dir() const = 0;

  virtual std::filesystem::path user_data_path() const;

  virtual std::filesystem::path site_data_path() const;

  virtual std::filesystem::path user_config_path() const;

  virtual std::filesystem::path site_config_path() const;

  virtual std::filesystem::path user_cache_path() const;

  virtual std::filesystem::path site_cache_path() const;

  virtual std::filesystem::path user_state_path() const;

  virtual std::filesystem::path user_log_path() const;

  virtual std::filesystem::path user_documents_path() const;

  virtual std::filesystem::path user_downloads_path() const;

  virtual std::filesystem::path user_pictures_path() const;

  virtual std::filesystem::path user_videos_path() const;

  virtual std::filesystem::path user_music_path() const;

  virtual std::filesystem::path user_desktop_path() const;

  virtual std::filesystem::path user_runtime_path() const;

  virtual std::filesystem::path site_runtime_path() const;
};

} // namespace api
} // namespace platformdirs