cmake_minimum_required( VERSION 3.13 )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( NET_HEADERS include/Client.h )
set( NET_SOURCES lib/Client.cpp )

add_library(network STATIC ${NET_HEADERS} ${NET_SOURCES})

target_include_directories(network PUBLIC .)
