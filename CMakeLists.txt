project(Flash)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

#######################################
# SFML linking:
set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

#######################################
# Compiler flags:
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD} -pthread")
#######################################
# Source files import:
set(MAIN init/main.cpp)

# Including engine files:
include(engine/engine-build.cmake)

#######################################
# Executable file linking:
add_executable(${PROJECT_NAME} ${MAIN} ${ENGINE})

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
