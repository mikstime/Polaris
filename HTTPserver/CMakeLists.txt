cmake_minimum_required(VERSION 3.13)
project(friend_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Boost REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp include/data.h lib/data.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
