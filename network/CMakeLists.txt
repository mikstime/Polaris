cmake_minimum_required( VERSION 3.15 )

project( network )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( GTest REQUIRED )

set( HEADERS include/network.h )
set( SOURCES lib/network.cpp )

add_executable(network network.cpp network.h)

include_directories( ${GTEST_INCLUDE_DIRS} )

add_executable( NetworkTest test/test.cpp )
