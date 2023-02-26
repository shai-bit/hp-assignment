cmake_minimum_required(VERSION 3.10)

project(listDir)

find_package(Boost PATHS ${CMAKE_SOURCE_DIR}/libs/ REQUIRED COMPONENTS filesystem)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(listDir src/listDir.cpp)

target_link_libraries(listDir ${Boost_LIBRARIES})