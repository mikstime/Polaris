cmake_minimum_required(VERSION 3.5)

project(polaris LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(polaris
  main.cpp
  lib/mainwindow.cpp
  include/mainwindow.h
  lib/controller.cpp
  include/controller.h
  lib/filehandler.cpp
  include/filehandler.h
)

target_link_libraries(polaris PRIVATE Qt5::Widgets)
