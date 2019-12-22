cmake_minimum_required(VERSION 3.13)
project(http)

set(CMAKE_CXX_STANDARD 17)

find_package (Boost REQUIRED COMPONENTS system filesystem)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} boostServer.h main.cpp boostServer.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
