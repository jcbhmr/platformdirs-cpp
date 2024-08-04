#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>

namespace platformdirs {
namespace utils {

// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}


inline auto home_path() -> std::filesystem::path {
#if __COSMOPOLITAN__
    if (IsWindows()) {
        if (auto const userprofile_dir = std::getenv("USERPROFILE")) {
            return std::filesystem::path(userprofile_dir);
        } else {
            throw std::runtime_error("%USERPROFILE% not set");
        }
    } else {
        if (auto const home_dir = std::getenv("HOME")) {
            return std::filesystem::path(home_dir);
        } else {
            throw std::runtime_error("$HOME not set");
        }
    }
#elif _WIN32
    if (auto const userprofile_dir = std::getenv("USERPROFILE")) {
        return std::filesystem::path(userprofile_dir);
    } else {
        throw std::runtime_error("%USERPROFILE% not set");
    }
#else
    if (auto const home_dir = std::getenv("HOME")) {
        return std::filesystem::path(home_dir);
    } else {
        throw std::runtime_error("$HOME not set");
    }
#endif
}

inline std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

inline std::string pathsep() {
    
        #if __COSMOPOLITAN__
        return IsWindows() ? ";" : ":";
        #elif _WIN32
        return ";";
        #else
        return ":";
        #endif
}

inline std::string join(const std::vector<std::string> &lst, const std::string &delim)
{
    std::string ret;
    for(const auto &s : lst) {
        if(!ret.empty())
            ret += delim;
        ret += s;
    }
    return ret;
}

}
}
