cmake_minimum_required(VERSION 3.15)

project(MainApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(HEADERS include/controller.h)
set(SOURCES lib/controller.cpp)

add_library(ControllerLib STATIC ${HEADERS} ${SOURCES})

target_include_directories(ControllerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)

target_link_libraries(ControllerLib PRIVATE Qt5::Widgets)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(ControllerLibTests tests/controller_tests.cpp)
target_link_libraries(ControllerLibTests ControllerLib Qt5::Widgets ${CMAKE_DL_LIBS} ${GTEST_LIBRARIES})
