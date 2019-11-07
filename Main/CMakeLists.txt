cmake_minimum_required(VERSION 3.15)

project(Main LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES lib/controller.cpp lib/filehandler.cpp lib/mainwindow.cpp)
set(HEADERS include/controller.h include/filehandler.h include/mainwindow.h)
add_library(MainLib STATIC ${SOURCES} ${HEADERS})
target_include_directories(MainLib PUBLIC .)
target_link_libraries(MainLib PRIVATE Qt5::Widgets)

add_executable(Main
  main.cpp
)

target_link_libraries(Main PRIVATE MainLib Qt5::Widgets)
