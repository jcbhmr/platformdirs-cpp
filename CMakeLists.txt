cmake_minimum_required(VERSION 3.29)

project(platformdirs
    VERSION 4.2.2
    LANGUAGES CXX
)
set(project_definitions PROJECT_NAME="${PROJECT_NAME}" PROJECT_VERSION="${PROJECT_VERSION}" PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR} PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR} PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH} PROJECT_VERSION_TWEAK=${PROJECT_VERSION_TWEAK})

include(FetchContent)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        11.0.2
)

# FMT_OS doesn't work with cosmocc
set(FMT_OS OFF)
FetchContent_MakeAvailable(fmt)

add_library(platformdirs)
target_sources(platformdirs PRIVATE src/platformdirs/api.cpp src/platformdirs/unix.cpp src/platformdirs/version.cpp)
target_include_directories(platformdirs PUBLIC include)
target_compile_features(platformdirs PRIVATE cxx_std_23)
# cosmocc has exceptions off by default
target_compile_options(platformdirs PRIVATE -fexceptions)
target_link_libraries(platformdirs PRIVATE fmt::fmt)
target_compile_definitions(platformdirs PRIVATE ${project_definitions})

add_executable(platformdirs_exe)
set_property(TARGET platformdirs_exe PROPERTY OUTPUT_NAME platformdirs)
target_sources(platformdirs_exe PRIVATE src/platformdirs_exe.cpp)
target_compile_features(platformdirs_exe PRIVATE cxx_std_23)
# cosmocc has exceptions off by default
target_compile_options(platformdirs_exe PRIVATE -fexceptions)
target_link_libraries(platformdirs_exe PRIVATE fmt::fmt platformdirs)
target_compile_definitions(platformdirs_exe PRIVATE ${project_definitions})
