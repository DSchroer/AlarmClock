include_directories(../../drivers/include)

FILE(GLOB_RECURSE main_SRC ./**.cpp ./**.hpp ./**.c)

if(LOCAL)
    add_library(firmware_core ${main_SRC})
    target_link_libraries(firmware_core drivers_pc)
else()
    include(~/Projects/cmake-avr/generic-gcc-avr.cmake)

    add_avr_library(firmware_core ${main_SRC})
    target_link_libraries(firmware_core-${AVR_MCU} drivers_avr-${AVR_MCU})
endif()
