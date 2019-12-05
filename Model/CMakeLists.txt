cmake_minimum_required(VERSION 3.15)

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

target_link_libraries(polarisModel_lib STATIC ${Boost_LIBRARIES} polarisUtils_lib )
target_link_libraries( tests_gtest public polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES} ${SOURCE_TESTS})
target_include_directories(polarisModel_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
##Tests for GraphInterface class
add_executable(graph_interface_tests lib/GraphInterface/graph_interface_tests.cpp)
target_link_libraries(graph_interface_tests polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES})
#Tests for ModelInterface class
add_executable(model_interface_tests lib/ModelInterface/model_interface_tests.cpp)
target_link_libraries(model_interface_tests polarisModel_lib ${Boost_LIBRARIES} ${GTEST_LIBRARIES} ${SOURCE_TESTS})
#Tests for Model
add_executable(model_tests model_tests.cpp)