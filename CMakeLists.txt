cmake_minimum_required(VERSION 3.21)
project(CPUProcess)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPUProcess main.cpp Queue.cpp Queue.h CPU.cpp CPU.h)
