cmake_minimum_required(VERSION 3.2)

include_directories(lib)
project(console_minesweeper)

set( SRC
     src/main.c
     src/cell.c
     src/field.c
     src/tester.c
     src/painter.c
   )

add_executable(${PROJECT_NAME} ${SRC})
