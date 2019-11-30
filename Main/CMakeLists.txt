cmake_minimum_required(VERSION 3.15)

project(MainApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

LINK_DIRECTORIES(/Polaris/Utils)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS_MAIN include/filehandler.h include/mainwindow.h include/view_sub.h)
set(SOURCES_MAIN lib/filehandler.cpp lib/mainwindow.cpp lib/view_sub.cpp)

add_library(MainLib STATIC ${HEADERS} ${SOURCES})

target_include_directories(MainLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)

target_link_libraries(MainLib PRIVATE polarisUtils_lib Qt5::Widgets)
