include_directories(../../drivers/include)

FILE(GLOB_RECURSE main_SRC ./**.cpp ./**.hpp ./**.c)

add_library(firmware_core ${main_SRC})
target_link_libraries(firmware_core drivers_pc)