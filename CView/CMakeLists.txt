cmake_minimum_required(VERSION 3.13)

#project(CView LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package( GTest REQUIRED )
find_package( Threads REQUIRED )


set(VIEW_HEADERS include/graph_parser.h include/graphic_connection.h include/graphic_item.h include/graphic_room.h
        include/graphic_view.h include/item_controller.h include/renderer.h include/view.h )
set(VIEW_SOURCES lib/graph_parser.cpp lib/graphic_connection.cpp  lib/graphic_item.cpp lib/graphic_room.cpp
        lib/graphic_view.cpp lib/item_controller.cpp lib/renderer.cpp lib/view.cpp)

add_library(CView STATIC ${VIEW_SOURCES} ${VIEW_HEADERS})
target_include_directories(CView PUBLIC .)

target_link_libraries(CView PRIVATE Qt5::Widgets)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/Utils)

add_executable(CView_test
        test/gtest_cview.cpp test/mock_controller.h test/mock_graphic_item.h test/mock_view.h
        )

target_link_libraries(CView_test polarisUtils_lib Qt5::Widgets ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}  -lgmock CView)