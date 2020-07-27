cmake_minimum_required(VERSION 3.16)
project(Flash)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

add_executable(Flash init/main.cpp init/bootstrap/globals.h)

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
