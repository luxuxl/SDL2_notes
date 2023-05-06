cmake_minimum_required(VERSION 3.25)
project(SimpleWindow)

set(CMAKE_CXX_STANDARD 17)
include_directories(/opt/local/include/)
link_directories(/opt/local/lib/)
link_libraries(SDL2)

add_executable(SimpleWindow main.cpp)
