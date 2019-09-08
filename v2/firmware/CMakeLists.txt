cmake_minimum_required(VERSION 3.14)
project(firmware)

option(LOCAL "Should be local build" OFF)

set(CMAKE_CXX_STANDARD 17)
set(AVR_MCU atmega328p)
set(MCU atmega328p)
set(MCU_SPEED 800000UL)

set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER avrispmkII)
set(AVR_UPLOADTOOL_PORT usb)

if(LOCAL)
    add_definitions(-DLOCAL)
endif()

add_definitions(-DF_CPU=800000UL)

add_subdirectory(src/tests)

include_directories(src/core)
include_directories(drivers/include)

add_subdirectory(src/core)

if(LOCAL)
    add_subdirectory(drivers/pc)
    add_executable(firmware src/main.cpp)
    target_link_libraries(firmware drivers_pc)
    target_link_libraries(firmware firmware_core)
else()
    include(~/Projects/cmake-avr/generic-gcc-avr.cmake)

    add_subdirectory(drivers/avr)

    add_avr_executable(firmware src/main.cpp)

    target_link_libraries(firmware-${AVR_MCU}.elf drivers_avr-${AVR_MCU})
    target_link_libraries(firmware-${AVR_MCU}.elf firmware_core-${AVR_MCU})
endif()





