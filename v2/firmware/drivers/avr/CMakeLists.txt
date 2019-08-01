FILE(GLOB all_SRC ./**.cpp ./**.c)

include_directories(../include)
add_library(drivers_avr ${all_SRC})