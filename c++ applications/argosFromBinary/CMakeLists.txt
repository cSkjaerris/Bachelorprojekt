cmake_minimum_required(VERSION 3.13)
project(argosFromBinary)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(ArgosWrapperSources ArgosSimulatorWrapper.cpp ArgosSimulatorWrapper.h JNALink.cpp JNALink.h)

add_library(argosFromBinary SHARED ${ArgosWrapperSources})

include(FindPkgConfig)
find_package(JNALink REQUIRED)
include_directories(${JNALink_INCLUDEDIR})

find_package(Argos REQUIRED)
include_directories(${ARGOS_INCLUDEDIR})

find_package(Lua REQUIRED)
message(${LUA_INCLUDEDIR})
include_directories(${LUA_INCLUDEDIR})

add_executable(TestSimulationWrapper TestWrapper.cpp)

target_link_libraries(${PROJECT_NAME} ${ARGOS_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${JNALink_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY})
target_link_libraries(TestSimulationWrapper ${PROJECT_NAME})

