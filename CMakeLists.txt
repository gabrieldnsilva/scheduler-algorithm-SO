cmake_minimum_required(VERSION 3.30)
project(scheduler C)

set(CMAKE_C_STANDARD 11)

include_directories(scheduler)

add_executable(scheduler
    scheduler/main.c
    scheduler/scheduler.c
)
