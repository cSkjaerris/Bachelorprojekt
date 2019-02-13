cmake_minimum_required(VERSION 3.13)
project(HelloJNA)

set(CMAKE_CXX_STANDARD 17)
set(libSRCS library.cpp library.h CHelloJNA.cpp CHelloJNA.h)


add_library(HelloJNA SHARED ${libSRCS})
add_executable(MainTest main.cpp)

target_link_libraries(MainTest HelloJNA)