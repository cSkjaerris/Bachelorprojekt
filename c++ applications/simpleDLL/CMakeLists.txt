cmake_minimum_required(VERSION 3.13)
project(simpleDLL)

set(CMAKE_CXX_STANDARD 17)

add_library(simpleDLL SHARED simpleDLL.cpp simpleDLL.h Foo.cpp Foo.h)