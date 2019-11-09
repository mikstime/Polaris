cmake_minimum_required( VERSION 3.15 )

project( isometry )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( GTest REQUIRED )

set( HEADERS include/isometry.h )
set( SOURCES lib/isometry.cpp )

add_library( ${PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS} )

target_include_directories( ${PROJECT_NAME}_lib PUBLIC . )

include_directories( ${GTEST_INCLUDE_DIRS} )

add_executable( isometryTest test/isometry_test.cpp )