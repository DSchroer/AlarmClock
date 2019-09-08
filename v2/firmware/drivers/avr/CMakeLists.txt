FILE(GLOB all_SRC ./*/**.cpp ./*/**.c ./**.cpp)

message(STATUS ${all_SRC})

include_directories(../include)
add_avr_library(drivers_avr ${all_SRC})