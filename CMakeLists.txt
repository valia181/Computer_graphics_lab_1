cmake_minimum_required(VERSION 3.20)
project(lab1_opengl)

set(CMAKE_CXX_STANDARD 17)

set(GLUT_ROOT_PATH ${CMAKE_SOURCE_DIR}/libs/freeglut)

include_directories(${GLUT_ROOT_PATH}/include)

link_directories(${GLUT_ROOT_PATH}/lib/x64)

add_executable(lab1_opengl main.cpp)

target_link_libraries(lab1_opengl freeglut opengl32 glu32)