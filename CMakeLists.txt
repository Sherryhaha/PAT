cmake_minimum_required(VERSION 3.3)
project(PAT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES AaddB.cpp)
add_executable(PAT ${SOURCE_FILES})