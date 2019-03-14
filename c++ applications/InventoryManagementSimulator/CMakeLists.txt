cmake_minimum_required(VERSION 3.13)
project(InventoryManagementSimulator)

set(CMAKE_CXX_STANDARD 17)

add_library(InventoryManagementSimulator SHARED InventoryManagementSimulator.cpp InventoryManagementSimulator.h Shop.h Product.h Inventory.h Customer.h Vendor.h)

add_executable(ManagementSimulatorTest main.cpp)

target_link_libraries(ManagementSimulatorTest InventoryManagementSimulator)