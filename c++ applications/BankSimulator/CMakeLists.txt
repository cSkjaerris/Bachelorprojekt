cmake_minimum_required(VERSION 3.13)
project(BankSimulator)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_library(BankSimulator SHARED BankSimulator.cpp BankSimulator.h)

add_executable(BankSimulatorTest main.cpp)

include(FindPkgConfig)
find_package(JNALink REQUIRED)
include_directories(${JNALink_INCLUDEDIR})

message(${JNALink_LIBRARY})

target_link_libraries(${PROJECT_NAME} ${JNALink_LIBRARY})

target_link_libraries(BankSimulatorTest ${PROJECT_NAME})

