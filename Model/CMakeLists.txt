cmake_minimum_required(VERSION 3.15)
project(polarisModel)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Catch2 REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS include/Graph/Graph.h
        include/GraphConnection/GraphConnection.h
        include/GraphElement/GraphElement.h
        include/GraphNode/GraphNode.h
        include/Model.h
        include/Search/Search.h)

set(SOURCE  lib/Graph/Graph.cpp
            lib/GraphConnection/GraphConnection.cpp
            lib/GraphElement/GraphElement.cpp
            lib/GraphNode/GraphNode.cpp
            lib/Model.cpp
            lib/Search/Search.cpp)

#target_link_libraries(polarisModel PRIVATE Qt5::Widgets)
#Static library
add_library(polarisModel_lib ${HEADERS} ${SOURCE})
target_include_directories(polarisModel_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
#Tests for GraphElement class
add_executable(graph_element_tests lib/GraphElement/graph_element_tests.cpp)
target_link_libraries(graph_element_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for Graph class
add_executable(graph_tests lib/Graph/graph_tests.cpp)
target_link_libraries(graph_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for GraphConnection class
add_executable(graph_connection_tests lib/GraphConnection/graph_connection_tests.cpp)
target_link_libraries(graph_connection_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for GraphNode class
add_executable(graph_node_tests lib/GraphNode/graph_node_tests.cpp)
target_link_libraries(graph_node_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for Model
add_executable(model_tests model_tests.cpp)
target_link_libraries(model_tests PUBLIC Catch2::Catch2 polarisModel_lib Qt5::Core)
#Tests for Search
add_executable(search_tests lib/Search/search_tests.cpp)
target_link_libraries(search_tests PUBLIC Catch2::Catch2 polarisModel_lib)