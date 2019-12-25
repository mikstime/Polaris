cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package( GTest REQUIRED )
find_package( Threads REQUIRED )
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS include/Graph/Graph.h
            include/GraphInterface/GraphInterface.h
            include/Model/Model.h
            include/ModelProxy/ModelProxy.h
            include/ModelInterface/ModelInterface.h
            include/ModelSubscriber/ModelSubscriber.h
            include/ModelObserver/ModelObserver.h
            include/Search/Search.h
            include/Search/PriorityQueue.h
        include/ModelToString/ModelAndString.h)

set(SOURCE  lib/GraphInterface/GraphInterface.cpp
            lib/ModelProxy/ModelProxy.cpp
            lib/ModelObserver/ModelObserver.cpp
            lib/ModelInterface/ModelInterface.cpp
            lib/Search/Search.cpp
        lib/ModelToString/ModelAndString.cpp
        )

set( SOURCE_TESTS   lib/GraphInterface/graph_interface_tests.cpp
#                    lib/ModelObserver/model_observer_tests.cpp outdated. No mocks provided yet
                    lib/ModelInterface/model_interface_tests.cpp )
#                    include/ModelSubscriber/mock_sub.h outdated. No mocks provided yet
#Static library

add_library( Model STATIC ${HEADERS} ${SOURCE} )
target_include_directories( Model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/Utils )

#include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${GTEST_INCLUDE_DIRS} )
include_directories( ${GMOCK_INCLUDE_DIRS} )
include_directories( ${PROJECT_SOURCE_DIR}/Utils/ )

target_link_libraries( Model ${Boost_LIBRARIES} Utils Qt5::Widgets)
#Tests for GraphInterface class
#add_executable( graph_interface_tests lib/GraphInterface/graph_interface_tests.cpp )
#target_link_libraries( graph_interface_tests Model ${GTEST_LIBRARIES} )

#Tests for ModelInterface class
#add_executable( model_interface_tests lib/ModelInterface/model_interface_tests.cpp )
#target_link_libraries( model_interface_tests Model ${GTEST_LIBRARIES} )
#Tests for Search
#
#Model tests
add_executable( model_tests model_tests.cpp )
target_link_libraries( model_tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} Model )
add_executable( model_and_string_tests lib/ModelToString/model_and_string_test.cpp )
target_link_libraries( model_and_string_tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} Model )