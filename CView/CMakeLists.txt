cmake_minimum_required(VERSION 3.15)

project(CView LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package( GTest REQUIRED )
find_package( Threads REQUIRED )

set(SOURCES lib/graphic_view.cpp lib/graphic_room.cpp lib/graphic_connection.cpp lib/graphic_scene.cpp
        lib/graph_parser.cpp lib/view.cpp)
set(HEADERS include/graphic_view.h include/graphic_room.h include/graphic_connection.h include/graphic_scene.h
        include/graph_parser.h include/view.h)
add_library(CView STATIC ${SOURCES} ${HEADERS})
target_include_directories(CView PUBLIC .)
target_link_libraries(CView PRIVATE Qt5::Widgets)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

add_executable(CView_test
    test/gtest_cview.cpp
    test/mock_controller.h
)

target_link_libraries(CView_test Qt5::Widgets ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}  -lgmock CView)
