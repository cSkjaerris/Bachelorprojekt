cmake_minimum_required(VERSION 3.13)
project(Simulator)

set(CMAKE_CXX_STANDARD 17)

add_library(Simulator SHARED JNASimulatorLink.cpp JNASimulatorLink.h DiscreteEventSimulator.cpp DiscreteEventSimulator.h)

add_executable(SimulatorTest main.cpp)

target_link_libraries(SimulatorTest Simulator)