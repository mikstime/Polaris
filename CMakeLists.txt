cmake_minimum_required(VERSION 3.13)
set(Qt5_DIR "~/Qt/5.13.2/clang_64/lib/cmake/Qt5")
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )
project(MainApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(Controller)
add_subdirectory(CView)
add_subdirectory(Main)
add_subdirectory(Model)
add_subdirectory(Utils)

add_executable(MainApp main.cpp)

target_link_libraries(MainApp PRIVATE Main Controller CView Model Utils Qt5::Widgets)
