cmake_minimum_required(VERSION 3.10)

project(dune_shell C)

add_executable(dune_shell
    src/main.c
    src/input.c
    src/execute.c
    src/builtin.c
)