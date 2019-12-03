cmake_minimum_required(VERSION 3.15)

project(MainApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)


set(MAIN_HEADERS Main/include/button_click_handler.h Main/include/node_form.h Main/include/mainwindow.h Main/include/view_sub.h)
set(MAIN_SOURCES Main/lib/button_click_handler.cpp Main/lib/node_form.cpp Main/lib/mainwindow.cpp Main/lib/view_sub.cpp)

add_subdirectory(CView)
add_subdirectory(Utils)

add_executable(MainApp ${MAIN_HEADERS} ${MAIN_SOURCES}
               main.cpp)

target_link_libraries(MainApp PRIVATE CView polarisUtils_lib Qt5::Widgets)