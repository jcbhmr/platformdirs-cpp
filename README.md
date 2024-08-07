# platformdirs for C++

📂 Python's [platformdirs](https://pypi.org/project/platformdirs/) module for C++

<table align=center><td>

```cpp
auto dirs = platformdirs::platform_dirs(app_name, app_author, "1.0");
std::println("user_data_dir: {}", dirs.user_data_dir());
std::println("user_config_dir: {}", dirs.user_config_dir());
std::println("user_cache_dir: {}", dirs.user_cache_dir());
std::println("user_state_dir: {}", dirs.user_state_dir());
std::println("user_log_dir: {}", dirs.user_log_dir());
std::println("...and more!");
```

```
user_data_dir: ~/.local/share/MyApp/1.0
user_config_dir: ~/.config/MyApp/1.0
user_cache_dir: ~/.cache/MyApp/1.0
user_state_dir: ~/.local/state/MyApp/1.0
user_log_dir: ~/.local/state/MyApp/1.0/log
...and more!
```

</table>

🐍 Same API surface as [platformdirs](https://pypi.org/project/platformdirs/) \
🔺 Works great with CMake \
💅 Uses platformdirs' opinionated directories \
📂 Works on Windows \
🌌 Works with [cosmocc](https://github.com/jart/cosmopolitan/tree/master/tool/cosmocc)!

## Installation

![CMake](https://img.shields.io/static/v1?style=for-the-badge&message=CMake&color=064F8C&logo=CMake&logoColor=FFFFFF&label=)

<dl>
<dt>CMake <code>find_package()</code> with <code>FetchContent</code> fallback
<dd>

```cmake
include(FetchContent)
FetchContent_Declare(platformdirs
    GIT_REPOSITORY https://github.com/jcbhmr/platformdirs-cpp.git
    GIT_TAG v0.1.0
    FIND_PACKAGE_ARGS 0.1.0...<1)
# Will try find_package(platformdirs 0.1.0...<1) first
FetchContent_MakeAvailable(platformdirs)

# ...

# Now link it into your app/lib target
target_link_libraries(myapp platformdirs::platformdirs)
target_link_libraries(mylib platformdirs::platformdirs)
```

</dl>

## Usage

![C++](https://img.shields.io/static/v1?style=for-the-badge&message=C%2B%2B&color=00599C&logo=C%2B%2B&logoColor=FFFFFF&label=)

<div><code>main.cpp</code></div>

```cpp
#include <print>
#include <platformdirs.h>

int main() {
    std::println("my app config: {}", platformdirs::user_config_dir("myapp", "me", "1.2.3"));
    return 0;
}
```

[📚 See the complete API surface on the website](https://jcbhmr.me/platformdirs/)

💡 Pro tip: there's an included `platformdirs` executable which prints a report of all the config dirs for you. It's great for debugging! 😉

## Development

![CMake](https://img.shields.io/static/v1?style=for-the-badge&message=CMake&color=064F8C&logo=CMake&logoColor=FFFFFF&label=)

```sh
cmake --workflow --preset default
cmake --workflow --preset test
```

💡 You can cut down on the repetative `cmake --workflow --preset` with an `alias cmakew="cmake --workflow --preset"` or similar.
