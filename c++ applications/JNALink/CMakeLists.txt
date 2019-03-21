cmake_minimum_required(VERSION 3.13)
project(JNALink)

set(CMAKE_CXX_STANDARD 17)

add_library(JNALink SHARED JNALink.h SimulatorLink.h JNALink.cpp)