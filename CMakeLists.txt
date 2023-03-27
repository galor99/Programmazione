cmake_minimum_required(VERSION 3.24)
project(progetto)

set(CMAKE_CXX_STANDARD 17)

add_executable(progetto main.cpp Task.cpp Task.h Date.cpp Date.h TodoList.cpp TodoList.h)
