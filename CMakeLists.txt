cmake_minimum_required(VERSION 3.12)
project(platformer)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the source file locations
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE MODELS ${CMAKE_CURRENT_SOURCE_DIR}/src/models/*.cpp)
file(GLOB DEPENDENCIES ${CMAKE_CURRENT_SOURCE_DIR}/src/dep/*.cpp)
file(GLOB LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a)
set(SOURCES ${SRC} ${MODELS} ${DEPENDENCIES})

add_executable(platformer ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(assimp CONFIG REQUIRED)

if(NOT ${OPENGL_FOUND})
  message("Could not find package OpenGL")
elseif(NOT ${ASSIMP_FOUND})
  message("Coult not find package Assimp")
else()
  target_include_directories(platformer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${OPENGL_INCLUDE_DIRS} ${ASSIMP_INCLUDE_DIRS})
  target_link_libraries(platformer PRIVATE ${OPENGL_LIBRARIES} ${LIBS} assimp::assimp) 
endif()
