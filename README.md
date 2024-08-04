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

```cmake
include(FetchContent)
FetchContent_Declare(platformdirs
    GIT_REPOSITORY https://github.com/jcbhmr/platformdirs-cpp.git
    GIT_TAG v0.1.0
)
FetchContent_MakeAvailable(platformdirs)
target_link_libraries(my-app platformdirs)
```

## Usage

<table><td>

<div><code>main.cpp</code></div>

```cpp
#include <print>
#include <platformdirs.h>

int main() {
    std::println("user config: {}", platformdirs::user_config_dir());
    std::println("user cache (myapp by me): {}", platformdirs::user_cache_dir("myapp", "me"));
    return 0;
}
```

<tr><td>

```
user config: ~/.local/config
user cache (myapp by me): ~/.local/cache/me/myapp TODO!
```

</table>

~~[📚 See the complete API surface on the website](https://jcbhmr.me/platformdirs/)~~

💡 Pro tip: there's an included `platformdirs` executable which prints a report of all the config dirs for you. It's great for debugging! 😉

## Development

<dl>
<dt>Compile everything using the system C/C++ toolchain
<dd>

```sh
cmake --workflow --preset default
cmake --workflow --preset release
```

<dt>Compile everything using a different C/C++ toolchain
<dd>

```sh
cmake --workflow --preset clang
cmake --workflow --preset cosmocc
cmake --workflow --preset gcc
cmake --workflow --preset zig-cc
cmake --workflow --preset zig-cc-target-wasm32-wasi-musl
cmake --workflow --preset zig-cc-target-* # There's more!
```

<dt>Compile and run tests
<dd>

```sh
cmake --workflow --preset test # (system toolchain)
cmake --workflow --preset test-cosmocc
```

<dt>Run tasks defined in <code>task.cmake</code>
<dd>

```sh
cmake --workflow --preset format
cmake --workflow --preset lint
```

<dt>Compile and package
<dd>

```sh
cmake --workflow --preset package # (system toolchain)
cmake --workflow --preset package-cosmocc
```

</dl>

💡 You can cut down on the repetative `cmake --workflow --preset` with an `alias cmakew="cmake --workflow --preset"` or similar.
