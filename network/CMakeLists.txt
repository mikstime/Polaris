cmake_minimum_required( VERSION 3.15 )

project( network )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( GTest REQUIRED )

set( HEADERS include/Client.h )
set( SOURCES lib/Client.cpp )

add_executable(network Client.cpp Client.h)

include_directories( ${GTEST_INCLUDE_DIRS} )

add_executable( ClientTest test/test.cpp )
