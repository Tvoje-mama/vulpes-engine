cmake_minimum_required(VERSION 3.0.2)
project(vulpes-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lX11 -lXxf86vm -lXrandr -lGL -lGLU -lXi -ldl -lXcursor -lXinerama")

find_package(glfw3 3.2.1 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(SOURCE_FILES src/main.cpp src/shaders/ShaderLoader.cpp src/shaders/ShaderLoader.h)

add_executable(vulpes-engine ${SOURCE_FILES})

target_link_libraries(vulpes-engine ${OPENGL_gl_LIBRARY} glfw3 GLEW)
