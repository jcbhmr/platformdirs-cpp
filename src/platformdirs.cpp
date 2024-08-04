#include <filesystem>
#include <string>
#include <fmt/format.h>

namespace platformdirs {

class platform_dirs_abc {

public:
    /** @returns data directory tied to the user */
    virtual std::string user_data_dir() const = 0;

    /** @returns data directory shared by users */
    virtual std::string site_data_dir() const = 0;

    /** @returns config directory tied to the user */
    virtual std::string user_config_dir() const = 0;

    /** @returns config directory shared by users */
    virtual std::string site_config_dir() const = 0;

    /** @returns cache directory tied to the user */
    virtual std::string user_cache_dir() const = 0;

    /** @returns cache directory shared by users */
    virtual std::string site_cache_dir() const = 0;

    /** @returns state directory tied to the user */
    virtual std::string user_state_dir() const = 0;

    // snip

    /** @returns data path tied to the user */
    std::filesystem::path user_data_path() const {
        return std::filesystem::path(this->user_data_dir());
    }

    // snip

    /** @returns iterator: all user and site configuration directories */
    std::vector<std::string> iter_config_dirs() const {
        return std::vector<std::string>{this->user_config_dir(), this->site_config_dir()};
    }

    // snip


}

#if __COSMOPOLITAN__
using platform_dirs = cosmopolitan;
#endif

std::string user_data_dir(const std::string_view appname, const std::string_view appauthor) {

}

} // namespace platformdirs