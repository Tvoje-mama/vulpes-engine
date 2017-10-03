cmake_minimum_required(VERSION 3.7)
project(vulpes-engine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(SOURCE_FILES main.cpp main.cpp)
add_executable(vulpes-engine ${SOURCE_FILES})
target_link_libraries(vulpes-engine ${OPENGL_gl_LIBRARY} glfw)

