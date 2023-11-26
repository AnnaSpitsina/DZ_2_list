cmake_minimum_required(VERSION 3.5)

project(DZ_2_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DZ_2_list main.cpp list_function.h)

install(TARGETS DZ_2_list
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
