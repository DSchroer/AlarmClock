include(GoogleTest)

include_directories(../core)
include_directories(../../drivers/include)

add_executable(AlarmTests alarms/alarm_test_runner.cpp)
target_link_libraries(AlarmTests gtest gtest_main firmware_core)

gtest_add_tests(AlarmTests "" AUTO)
