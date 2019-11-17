cmake_minimum_required(VERSION 3.15)
project(polarisModel)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Catch2 REQUIRED)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

set(Boost_USE_STATIC_LIBS        ON)
set(HEADERS include/Graph/Graph.h
            include/GraphInterface/GraphInterface.h
            include/GraphConnection/GraphConnection.h
            include/GraphElement/GraphElement.h
            include/GraphNode/GraphNode.h
            include/Model/Model.h
            include/ModelProxy/ModelProxy.h
            include/ModelInterface/ModelInterface.h
            include/ModelSubscriber/ModelSubscriber.h
            include/ModelObserver/ModelObserver.h
            include/Search/Search.h)

set(SOURCE  lib/GraphInterface/GraphInterface.cpp
            lib/ModelProxy/ModelProxy.cpp
            lib/GraphElement/GraphElement.cpp
            lib/ModelObserver/ModelObserver.cpp
            lib/ModelInterface/ModelInterface.cpp
            lib/Search/Search.cpp)
#Static library
add_library(polarisModel_lib ${HEADERS} ${SOURCE})

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})
add_executable( tests_gtest tests_gtest.cpp )

target_link_libraries(polarisModel_lib ${Boost_LIBRARIES})
target_link_libraries( tests_gtest public polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES})
target_include_directories(polarisModel_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
#Tests for GraphElement class
add_executable(graph_element_tests lib/GraphElement/graph_element_tests.cpp)
target_link_libraries(graph_element_tests PUBLIC Catch2::Catch2 polarisModel_lib)
##Tests for GraphInterface class
add_executable(graph_interface_tests lib/GraphInterface/graph_interface_tests.cpp)
target_link_libraries(graph_interface_tests polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES})
#Tests for ModelInterface class
add_executable(model_interface_tests lib/ModelInterface/model_interface_tests.cpp)
target_link_libraries(model_interface_tests polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES} lib/ModelObserver/model_observer_tests.cpp)
#Tests for Model
add_executable(model_tests model_tests.cpp)
target_link_libraries(model_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for ModelObserver
add_executable(model_observer_tests lib/ModelObserver/model_observer_tests.cpp)
target_link_libraries(model_tests PUBLIC Catch2::Catch2 polarisModel_lib)
#Tests for Search
add_executable(search_tests lib/Search/search_tests.cpp)
target_link_libraries(search_tests PUBLIC Catch2::Catch2 polarisModel_lib)