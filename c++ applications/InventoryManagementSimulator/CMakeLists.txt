cmake_minimum_required(VERSION 3.13)
project(InventoryManagementSimulator)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_library(InventoryManagementSimulator SHARED InventoryManagementSimulator.cpp InventoryManagementSimulator.h Shop.h Product.h Inventory.h Customer.h Vendor.h JNALink.cpp JNALink.h)

add_executable(ManagementSimulatorTest main.cpp)


include(FindPkgConfig)
find_package(JNALink REQUIRED)
include_directories(${JNALink_INCLUDEDIR})

#message( ${JNALink_LIBRARY} )

target_link_libraries(${PROJECT_NAME} ${JNALink_LIBRARY})

target_link_libraries(ManagementSimulatorTest InventoryManagementSimulator)

target_link_libraries(ManagementSimulatorTest ${JNALink_LIBRARY})