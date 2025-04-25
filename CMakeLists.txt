cmake_minimum_required(VERSION 3.5)
project(lab04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./Headers)

add_executable(lab04 ./src/main.cpp ./Headers/Header.hpp)
