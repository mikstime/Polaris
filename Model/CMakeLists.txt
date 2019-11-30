cmake_minimum_required(VERSION 3.15)
project(polarisModel)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

set(Boost_USE_STATIC_LIBS        ON)

set(HEADERS include/Graph/Graph.h
            include/GraphInterface/GraphInterface.h
            include/Model/Model.h
            include/ModelProxy/ModelProxy.h
            include/ModelInterface/ModelInterface.h
            include/ModelSubscriber/ModelSubscriber.h
            include/ModelObserver/ModelObserver.h
            include/Search/Search.h)

set(SOURCE  lib/GraphInterface/GraphInterface.cpp
            lib/ModelProxy/ModelProxy.cpp
            lib/ModelObserver/ModelObserver.cpp
            lib/ModelInterface/ModelInterface.cpp
            lib/Search/Search.cpp)

set( SOURCE_TESTS   lib/GraphInterface/graph_interface_tests.cpp
                    lib/ModelObserver/ModelObserver.cpp
                    lib/ModelInterface/model_interface_tests.cpp)
#Static library
add_library(polarisModel_lib ${HEADERS} ${SOURCE})

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})
include_directories( ../Utils )
add_executable( tests_gtest tests_gtest.cpp )