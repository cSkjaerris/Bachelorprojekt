cmake_minimum_required(VERSION 3.13)
project(BankSimulator)

set(CMAKE_CXX_STANDARD 17)

set(libraryPath "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/Simulator")

set(importedHeaders ${libraryPath}/SimulatorLink.h)
add_library(BankSimulator SHARED BankSimulator.cpp BankSimulator.h ${importedHeaders})


target_link_libraries(BankSimulator)
