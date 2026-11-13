cmake_minimum_required(VERSION 3.16)
project(tetris CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find packages first
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# 2. Collect your source files
file(GLOB SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(tetris ${SOURCES})

# 4. NOW apply your options and directories to the valid target
target_compile_options(tetris PRIVATE -g -Wall -Wextra -Wshadow)

target_include_directories(tetris PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# 5. Link libraries last
target_link_libraries(tetris PRIVATE 
    SDL3_image::SDL3_image
    SDL3::SDL3
)
