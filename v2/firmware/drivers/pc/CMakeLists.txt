FILE(GLOB all_SRC ./**.cpp ./**.c)

find_package(SFML 2.5 CONFIG REQUIRED COMPONENTS network audio graphics window system)

include_directories(../include)
add_library(drivers_pc ${all_SRC})

target_link_libraries(drivers_pc sfml-graphics sfml-window sfml-system)