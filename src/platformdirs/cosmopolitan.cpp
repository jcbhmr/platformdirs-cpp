#include <string>
#include <filesystem>
#include "utils.h"

namespace platformdirs {
namespace cosmopolitan {

class cosmopolitan : platform_dirs_abc {

public:
    virtual std::string user_data_dir() {
        if (IsWindows()) {

        } else if (IsXnu()) {
            
        } else {
            auto path = std::string(std::getenv("XDG_DATA_HOME"));
            platformdirs::utils::ltrim(path);
            platformdirs::utils::rtrim(path);
            if (path == "") {
                const auto home = std::filesystem::path(std::getenv("HOME"));
                if (home == "") {
                    throw std::runtime_error("HOME not set");
                }
                path = (home / ".local/share").string();
            }
            return this->append_app_name_and_version(path);
        }
    }

    // snip
}

} // namespace cosmopolitan
} // namespace platformdirs
