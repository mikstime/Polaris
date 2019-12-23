cmake_minimum_required( VERSION 3.13 )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package (Boost REQUIRED COMPONENTS thread)
find_package( Threads REQUIRED )

include_directories(${Boost_INCLUDE_DIRS})

set( NET_HEADERS include/Client.h include/data.h)
set( NET_SOURCES lib/Client.cpp lib/data.cpp)

add_library(network STATIC ${NET_HEADERS} ${NET_SOURCES})
target_include_directories(network PUBLIC .)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
