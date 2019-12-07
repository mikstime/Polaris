cmake_minimum_required(VERSION 3.13)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(HEADERS include/graph_controller.h
            include/view_controller.h)

set(SOURCES lib/graph_controller.cpp
            lib/view_controller.cpp)

add_library(Controller STATIC ${SOURCES} ${HEADERS})

target_include_directories(Controller PUBLIC .)

target_link_libraries(Controller PRIVATE Qt5::Widgets)

include_directories(${PROJECT_SOURCE_DIR}/Utils)
include_directories(${PROJECT_SOURCE_DIR}/Main)
include_directories(${PROJECT_SOURCE_DIR}/CView)
include_directories(${PROJECT_SOURCE_DIR}/Model)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(ControllerTests tests/view_controller_tests.cpp)
target_link_libraries(ControllerTests ControllerLib Qt5::Widgets ${CMAKE_DL_LIBS} ${GTEST_LIBRARIES})
