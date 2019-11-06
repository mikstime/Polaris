cmake_minimum_required(VERSION 3.15)

project(Isometry)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Isometry isometry.cpp isometry.h)