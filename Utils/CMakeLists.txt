cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( GTest REQUIRED )

set(HEADERS typedefs.h
            Meta/Meta.h
            GraphConnection/GraphConnection.h
            GraphNode/GraphNode.h
            GraphElement/GraphElement.h )

set(SOURCE  GraphConnection/GraphConnection.cpp
            GraphElement/GraphElement.cpp )
#Static library
add_library( Utils STATIC ${HEADERS} ${SOURCE} )
include_directories(${GTEST_INCLUDE_DIRS})
target_include_directories( Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

add_executable( utils_tests utils_tests.cpp)
target_link_libraries( utils_tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} Utils )