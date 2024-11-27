cmake_minimum_required(VERSION 3.27)
project(MatchSimu)

set(CMAKE_C_STANDARD 17)

add_executable(MatchSimu main.c
        simulation.h)
