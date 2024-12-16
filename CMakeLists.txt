# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)  # 指定CMake的最低版本
project(MyProject)                     # 项目名称

set(CMAKE_CXX_STANDARD 17)            # 设置C++标准
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找 SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(include/SDL2)
include_directories(include/comicReader)

add_executable(comicReader src/main.cpp)

target_link_libraries(comicReader SDL2::SDL2 SDL2_image::SDL2_image)