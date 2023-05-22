cmake_minimum_required(VERSION 3.5)
project(progetto)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googleTest)

set(SOURCE_FILES main.cpp Date.cpp Date.h Task.cpp Task.h TodoList.cpp TodoList.h)
add_executable(progetto main.cpp Date.cpp Date.h Task.cpp Task.h TodoList.cpp TodoList.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(core)
