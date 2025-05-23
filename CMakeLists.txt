cmake_minimum_required(VERSION 3.20)
project(Cplox LANGUAGES CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output compile_commands.json (for IDEs and tools)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find fmt (system install)
find_package(fmt REQUIRED)

# Add executable and sources
file(GLOB CPLOX_SOURCES "src/*.cpp")
add_executable(Cplox ${CPLOX_SOURCES})

# Link fmt
target_link_libraries(Cplox PRIVATE fmt::fmt)

# Optionally, set output directory for build artifacts
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
