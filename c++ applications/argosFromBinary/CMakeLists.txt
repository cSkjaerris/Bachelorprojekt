cmake_minimum_required(VERSION 3.13)
project(argosFromBinary)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(ArgosWrapperSources ArgosSimulatorWrapper.cpp ArgosSimulatorWrapper.h JNALink.cpp JNALink.h MultivestaLoopFunctions.cpp MultivestaLoopFunctions.h CForagingLoopFunctions.cpp CForagingLoopFunctions.h CFootBotForaging.cpp CFootBotForaging.h SimulatorLink.h)

add_library(argosFromBinary SHARED ${ArgosWrapperSources})

include(FindPkgConfig)
#find_package(JNALink REQUIRED)
#include_directories(${JNALink_INCLUDEDIR})

find_package(Argos REQUIRED)
include_directories(${ARGOS_INCLUDEDIR})

find_package(Lua REQUIRED)

include_directories(${LUA_INCLUDEDIR})

add_executable(TestSimulationWrapper TestWrapper.cpp)

target_link_libraries(${PROJECT_NAME} ${ARGOS_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${FOOTBOT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${MEDIA_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${ENTITY_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GENERIC_ROBOT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${DYNAMICS_2D_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${JNALink_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY})
target_link_libraries(TestSimulationWrapper ${PROJECT_NAME})


#Building controller

add_library(footbot_foraging SHARED CFootBotForaging.h CFootBotForaging.cpp)
target_link_libraries(footbot_foraging
        ${ARGOS_LIBRARY}
        ${FOOTBOT_LIBRARY}
        ${GENERIC_ROBOT_LIBRARY})

#Build for loop functions

# multivesta loop functions
add_library(multivesta_loop_functions SHARED MultivestaLoopFunctions.cpp MultivestaLoopFunctions.h)
target_link_libraries(multivesta_loop_functions
        ${ARGOS_LIBRARY}
        ${DYNAMICS_2D_LIBRARY}
        ${ENTITY_LIBRARY}
        ${FOOTBOT_LIBRARY}
        ${GENERIC_ROBOT_LIBRARY}
        ${MEDIA_LIBRARY})

# foraging
add_library(foraging_loop_functions SHARED CForagingLoopFunctions.h CForagingLoopFunctions.cpp)
target_link_libraries(foraging_loop_functions
        footbot_foraging
        ${ARGOS_LIBRARY}
        ${DYNAMICS_2D_LIBRARY}
        ${ENTITY_LIBRARY}
        ${FOOTBOT_LIBRARY}
        ${GENERIC_ROBOT_LIBRARY}
        ${MEDIA_LIBRARY})