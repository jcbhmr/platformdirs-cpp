#pragma once
#undef unix
#include <string>
#include <filesystem>
#include <optional>
#include <variant>
#include "api.h"

namespace platformdirs {
namespace unix {

class unix : public platformdirs::api::platform_dirs_abc {
public:

unix(const std::optional<std::string>& appname = std::nullopt, const std::variant<std::string, std::nullopt_t, bool>& appauthor = std::nullopt, const std::optional<std::string>& version = std::nullopt, bool roaming = false, bool multipath = false, bool opinion = true, bool ensure_exists = false);

std::string user_data_dir() const override;

std::string site_data_dir() const override;

// virtual std::string user_config_dir() const;

// virtual std::string site_config_dir() const;

// virtual std::string user_cache_dir() const;

// virtual std::string site_cache_dir() const;

// virtual std::string user_state_dir() const;

// virtual std::string user_log_dir() const;

// virtual std::string user_documents_dir() const;

// virtual std::string user_downloads_dir() const;

// virtual std::string user_pictures_dir() const;

// virtual std::string user_videos_dir() const;

// virtual std::string user_music_dir() const;

// virtual std::string user_desktop_dir() const;

// virtual std::string user_runtime_dir() const;

// virtual std::string site_runtime_dir() const;

private:
auto site_data_dirs() const -> std::vector<std::string>;

};

} // namespace unix
} // namespace platformdirs
