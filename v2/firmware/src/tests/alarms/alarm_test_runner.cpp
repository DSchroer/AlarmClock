#include "gtest/gtest.h"
#include "./alarm_tests.cpp"
#include "./alarm_manager_tests.cpp"
#include "./vector_tests.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
