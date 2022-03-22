cmake_minimum_required(VERSION 3.2)

include_directories(lib)
project(Mine)

set( SRC
     src/main.c
     src/cell.c
     src/field.c
   )

add_executable(${PROJECT_NAME} ${SRC})
