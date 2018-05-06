cmake_minimum_required(VERSION 3.10)
project(distr_sys)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O2")

message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

add_executable(distr_sys main.cpp MSQueue/Node.h MSQueue/MSQueue.h Exp/Exp.cpp Exp/Exp.h MutexQueue/MutexQueue.h)