cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(console_minesweeper LANGUAGES C)
set(CMAKE_CXX_STANDARD 18) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c18 -Werror -Wall -Wextra
-Wpedantic -fPIC -march=native -pthread -g -lm")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c18 -O2 -fPIC -march=native -pthread -lm")

include_directories(inc)
set(PROJECT_SOURCES_DIR src)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.c)


add_executable(${PROJECT_NAME} ${SOURCES})

