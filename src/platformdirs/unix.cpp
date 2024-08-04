#undef unix
#include "unix.h"
#include <string>
#include <filesystem>
#include <optional>
#include <variant>
#include <cstdlib>
#include "utils.h"

auto platformdirs::unix::unix::user_data_dir() const -> std::string {
    auto path = std::string(std::getenv("XDG_DATA_HOME"));
    platformdirs::utils::ltrim(path);
    platformdirs::utils::rtrim(path);
    if (path == "") {
        path = (platformdirs::utils::home_path() / ".local/share").string();
    }
    return this->append_app_name_and_version({path});
}

auto platformdirs::unix::unix::site_data_dirs() const -> std::vector<std::string> {
    auto path = std::string(std::getenv("XDG_DATA_DIRS"));
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

auto platformdirs::unix::unix::site_data_dir() const -> std::string {
    auto const dirs = this->site_data_dirs();
    if (!this->multipath) {
        return dirs.at(0);
    }
    return platformdirs::utils::join(dirs, platformdirs::utils::pathsep());
}
