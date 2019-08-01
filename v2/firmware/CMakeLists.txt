cmake_minimum_required(VERSION 3.14)
project(firmware)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(LOCAL)
add_definitions(-DF_CPU=800000UL)

include_directories(drivers/include)

FILE(GLOB_RECURSE main_SRC ./src/**.cpp ./src/**.hpp ./src/**.c)

add_subdirectory(drivers/pc)
#add_subdirectory(drivers/avr)

add_executable(firmware ${main_SRC})
target_link_libraries(firmware drivers_pc)