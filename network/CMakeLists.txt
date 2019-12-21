cmake_minimum_required( VERSION 3.13 )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( GTest REQUIRED )

set( HEADERS include/Client.h )
set( SOURCES lib/Client.cpp )

add_library(network STATIC ${HEADERS} ${SOURCES})

target_include_directories(network PUBLIC .)

include_directories( ${GTEST_INCLUDE_DIRS} )


