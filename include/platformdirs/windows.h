#pragma once
#include "api.h"
#include <filesystem>
#include <optional>
#include <string>
#include <variant>

namespace platformdirs {
namespace windows {

class windows : public platformdirs::api::platform_dirs_abc {
public:
  windows(const std::optional<std::string> &appname = std::nullopt,
          const std::variant<std::string, std::nullopt_t, bool> &appauthor =
              std::nullopt,
          const std::optional<std::string> &version = std::nullopt,
          bool roaming = false, bool multipath = false, bool opinion = true,
          bool ensure_exists = false);

  std::string user_data_dir() const override;

private:
  struct append_parts_options {
    std::optional<std::string> opinion_value;
  };
  std::string append_parts(
      const std::string &path,
      const platformdirs::windows::windows::append_parts_options &options = {})
      const;

public:
  std::string site_data_dir() const override;

  std::string user_config_dir() const override;

  std::string site_config_dir() const override;

  std::string user_cache_dir() const override;

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
};

} // namespace windows
} // namespace platformdirs
