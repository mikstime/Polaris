cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(HEADERS include/button_click_handler.h
            include/node_form.h
            include/connection_form.h
            include/mainwindow.h
            include/view_sub.h)

set(SOURCES lib/button_click_handler.cpp
            lib/node_form.cpp
            lib/connection_form.cpp
            lib/mainwindow.cpp
            lib/view_sub.cpp)

add_library(Main STATIC ${HEADERS} ${SOURCES})

target_include_directories(Main PUBLIC .)

target_link_libraries(Main PRIVATE Qt5::Widgets)

include_directories(${PROJECT_SOURCE_DIR}/Utils)
include_directories(${PROJECT_SOURCE_DIR}/Controller)
include_directories(${PROJECT_SOURCE_DIR}/CView)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(MainTests tests/filehandler_tests.cpp tests/mainwindow_tests.cpp)
target_link_libraries(MainTests ControllerLib Qt5::Widgets ${CMAKE_DL_LIBS} ${GTEST_LIBRARIES})
