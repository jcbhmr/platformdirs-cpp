cmake_minimum_required(VERSION 3.29)

# Project declaration
project(
  platformdirs
  VERSION 0.1.0
  DESCRIPTION "📂 Python's platformdirs module for C++"
  HOMEPAGE_URL "https://jcbhmr.me/platformdirs"
  LANGUAGES CXX)

# Main dependencies
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 11.0.2
  FIND_PACKAGE_ARGS 11.0.2...<12)
# FMT_OS doesn't work with Cosmopolitan
set(FMT_OS OFF)
FetchContent_MakeAvailable(fmt)

# Library targets
add_library(platformdirs)
add_library(platformdirs::platformdirs ALIAS platformdirs)
target_sources(
  platformdirs
  PRIVATE src/platformdirs.cpp
          src/platformdirs/api.cpp
          src/platformdirs/macos.cpp
          src/platformdirs/unix.cpp
          src/platformdirs/utils.cpp
          src/platformdirs/version.cpp
          src/platformdirs/windows.cpp)
target_include_directories(platformdirs PUBLIC include)
target_compile_features(platformdirs PRIVATE cxx_std_23)
# cosmocc has exceptions off by default
target_compile_options(platformdirs PRIVATE -fexceptions)
target_link_libraries(platformdirs PRIVATE fmt::fmt)
target_compile_definitions(platformdirs PRIVATE
PROJECT_VERSION="${PROJECT_VERSION}"
PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR}
PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH}
PROJECT_VERSION_TWEAK=${PROJECT_VERSION_TWEAK})

# Binary targets
add_executable(platformdirs_exe)
add_executable(platformdirs::platformdirs_exe ALIAS platformdirs_exe)
set_property(TARGET platformdirs_exe PROPERTY OUTPUT_NAME platformdirs)
target_sources(platformdirs_exe PRIVATE src/platformdirs_exe.cpp)
target_compile_features(platformdirs_exe PRIVATE cxx_std_23)
# cosmocc has exceptions off by default
target_compile_options(platformdirs_exe PRIVATE -fexceptions)
target_link_libraries(platformdirs_exe PRIVATE fmt::fmt platformdirs)
target_compile_definitions(platformdirs_exe PRIVATE
PROJECT_VERSION="${PROJECT_VERSION}"
PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR}
PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH}
PROJECT_VERSION_TWEAK=${PROJECT_VERSION_TWEAK})

# Testing
include(CTest)
if(BUILD_TESTING)
  add_test(NAME platformdirs COMMAND platformdirs_exe)
endif()

# Packaging
include(CPack)

# Installation
include(GNUInstallDirs)
install(TARGETS platformdirs platformdirs_exe)

# Tasks
if(BUILD_TESTING)
file(
    GLOB_RECURSE
    c_cxx_files
    src/*.c
    src/*.cpp
    src/*.cc
    src/*.cxx
    src/*.h
    src/*.hxx
    src/*.hh
    src/*.hpp
    include/*.h
    include/*.hxx
    include/*.hh
    include/*.hpp
    test/*.c
    test/*.cpp
    test/*.cc
    test/*.cxx
    test/*.h
    test/*.hxx
    test/*.hh
    test/*.hpp
    examples/*.c
    examples/*.cpp
    examples/*.cc
    examples/*.cxx
    examples/*.h
    examples/*.hxx
    examples/*.hh
    examples/*.hpp)
  file(
    GLOB_RECURSE
    cmake_files
    cmake/*.cmake
    src/*CMakeLists.txt
    src/*.cmake
    test/*CMakeLists.txt
    test/*.cmake)
  list(APPEND cmake_format_files CMakeLists.txt task.cmake)
  add_custom_target(format 
  COMMAND clang-format -i ${c_cxx_files}
  COMMAND cmake-format -i ${cmake_files}
  COMMAND_ECHO STDERR
  COMMAND_ERROR_IS_FATAL ANY
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  
  file(GLOB_RECURSE all_files .github/* cmake/* src/* examples/* test/* docs/*)
  list(APPEND .gitignore CMakeLists.txt CMakePresets.json README.md task.cmake)
  add_custom_target(lint COMMAND codespell -w ${all_files} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  
  find_package(Doxygen REQUIRED)
  set(DOXYGEN_EXCLUDE "${CMAKE_BINARY_DIR}")
  set(DOXYGEN_EXTRACT_ALL YES)
  set(DOXYGEN_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
  doxygen_add_docs(docs "${PROJECT_SOURCE_DIR}")

  add_custom_target(preview COMMAND python -m http.server WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html")
  add_dependencies(preview docs)
endif()
