cmake_minimum_required(VERSION 3.13)
project(SpikeWrapper)

set(CMAKE_CXX_STANDARD 17)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(DSSD REQUIRED)
include_directories(${DSSD_INCLUDE_DIRS})
list(APPEND LIBS ${DSSD_LIBRARIES})

find_package(Cvode REQUIRED)
include_directories(${CVODE_INCLUDE_DIRS})
list(APPEND LIBS ${CVODE_LIBRARIES})

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_NO_SYSTEM_PATHS TRUE)

if (Boost_NO_SYSTEM_PATHS)
    set(BOOST_ROOT /usr/local/Cellar/boost/1.69.0)
    set(BOOST_INCLUDE_DIRS &{BOOST_ROOT}/include)
    set(BOOST_LIBRARY_DIRS ${BOOST_ROOT}/lib)
endif (Boost_NO_SYSTEM_PATHS)

find_package(Boost REQUIRED COMPONENTS regex)
if(Boost_FOUND)
    add_definitions( -DUSE_BOOST )
    include_directories(${Boost_INCLUDE_DIRS})
    list(APPEND LIBS ${Boost_LIBRARIES})
endif()


add_library(SpikeWrapper SHARED SpikeWrapper.cpp SpikeWrapper.h JNALink.cpp JNALink.h)

find_package(Spike REQUIRED)
include_directories(${Spike_INCLUDEDIR})

include(FindPkgConfig)
find_package(JNALink REQUIRED)
include_directories(${JNALink_INCLUDEDIR})




target_link_libraries(${PROJECT_NAME} ${JNALink_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${CVODE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${DSSD_LIBRARIES})
target_link_libraries(${PROJECT_NAME} -Wl,-force_load ${Spike_LIBRARY} -Wl,-force_load)