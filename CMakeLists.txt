cmake_minimum_required(VERSION 3.24.2)
project(gocrazy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR)

if (APPLE)
  set(CMAKE_TOOLCHAIN_FILE "/Users/$ENV{USER}/Library/vcpkg/scripts/buildsystems/vcpkg.cmake")
  set(CMAKE_PREFIX_PATH "/Users/$ENV{USER}/Library/vcpkg/installed/arm64-osx/share")
endif()

include_directories(inc)

find_package(benchmark REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

list(APPEND project_libraries
benchmark::benchmark
nlohmann_json::nlohmann_json
)

add_subdirectory(src)

target_link_libraries(src PRIVATE ${project_libraries})