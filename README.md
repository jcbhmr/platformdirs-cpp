# platformdirs for C++

📂 Python's [platformdirs](https://pypi.org/project/platformdirs/) module for C++

<table align=center><td>

TODO

</table>

🐍 Same API surface as [platformdirs](https://pypi.org/project/platformdirs/) \
🔺 Works great with CMake \
💅 Uses platformdirs' opinionated directories \
📂 Works on Windows \
🌌 Works with [Cosmopolitan Libc](https://github.com/jart/cosmopolitan)!

## Installation

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

```sh
cmake --workflow --preset default
cmake --workflow --preset test
```

💡 You can cut down on the repetative `cmake --workflow --preset` with an `alias cmakew="cmake --workflow --preset"` or similar.
