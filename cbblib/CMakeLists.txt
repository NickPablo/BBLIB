project(cbblib)
cmake_minimum_required(VERSION 2.8)


include_directories("../bblib/")

add_executable(cbblib main.cpp)
target_link_libraries(cbblib bblib)

