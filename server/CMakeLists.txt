cmake_minimum_required(VERSION 3.10)
project(localhost)

set(CMAKE_CXX_STANDARD 17)

add_executable(localhost main.cpp lib/Server.cpp include/Server.h)
