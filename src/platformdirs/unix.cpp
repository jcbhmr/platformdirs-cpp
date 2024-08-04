#undef unix
#include "unix.h"
#include <string>
#include <filesystem>
#include <optional>
#include <variant>
#include <cstdlib>
#include "utils.h"

platformdirs::unix::unix::unix(const std::optional<std::string>& appname, const std::variant<std::string, std::nullopt_t, bool>& appauthor, const std::optional<std::string>& version, bool roaming, bool multipath, bool opinion, bool ensure_exists) : platformdirs::api::platform_dirs_abc(appname, appauthor, version, roaming, multipath, opinion, ensure_exists) { }

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

auto platformdirs::unix::unix::site_data_dirs() const -> std::vector<std::string> {
    auto path_c_str = std::getenv("XDG_DATA_DIRS");
    auto path = path_c_str ? std::string(path_c_str) : std::string();
    platformdirs::utils::ltrim(path);
    platformdirs::utils::rtrim(path);
    if (path == "") {
        path = std::string("/usr/local/share") + platformdirs::utils::pathsep() + "/usr/share";
    }
    auto appended = std::vector<std::string>();
    for (auto p : platformdirs::utils::split(path, platformdirs::utils::pathsep())) {
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
