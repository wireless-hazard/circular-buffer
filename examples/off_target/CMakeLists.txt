cmake_minimum_required(VERSION 3.10)

project(circular_buffer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app_wrapper actual_main.cpp ../../src/circular_queue.cpp ../main/app_main.cpp)
target_include_directories(app_wrapper PUBLIC ../main/include ../../include .)