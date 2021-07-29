cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(BrainpanShellGen LANGUAGES CXX)
set(BIN_PATH "../")
add_library(ShellGenLibs
        STATIC
            "../src/init.cpp"
            "../headers/arguments.h"
            "../headers/options.h"
            "../headers/exploit.h"
            "../src/exploit.cpp"
)

add_executable(ShellGen ../src/source.cpp)

target_link_libraries(ShellGen ShellGenLibs)