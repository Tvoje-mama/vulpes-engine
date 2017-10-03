cmake_minimum_required(VERSION 3.7)
project(vulpes-engine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)

set(SOURCE_FILES main.cpp main.cpp)
add_executable(cpp_app ${SOURCE_FILES})