cmake_minimum_required(VERSION 2.6)
project(brainfuck-interpreter)

set(CMAKE_BUILD_TYPE Release)

include_directories(src/)
file(GLOB SOURCES "src/*.c")
add_executable(brainfuck-interpreter ${SOURCES})

install(TARGETS brainfuck-interpreter DESTINATION /usr/local/bin)