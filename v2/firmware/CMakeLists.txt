cmake_minimum_required(VERSION 3.14)
project(firmware)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(LOCAL)
add_definitions(-DF_CPU=800000UL)

include_directories(src/core)
include_directories(drivers/include)

add_subdirectory(src/core)

add_subdirectory(drivers/pc)
#add_subdirectory(drivers/avr)

add_executable(firmware src/main.cpp)
target_link_libraries(firmware drivers_pc)
target_link_libraries(firmware firmware_core)

add_subdirectory(src/tests)