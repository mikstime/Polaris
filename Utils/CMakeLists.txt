cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

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

add_executable( graph_element_tests GraphElement/graph_element_tests.cpp )
target_link_libraries(graph_element_tests PUBLIC  Utils )
