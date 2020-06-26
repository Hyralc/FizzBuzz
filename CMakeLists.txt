cmake_minimum_required(VERSION 3.5)
project(Fizzbuzz LANGUAGES CXX)


# finds boost, triggers an error otherwise
find_package(Boost 1.65 REQUIRED COMPONENTS unit_test_framework)
enable_testing()


add_subdirectory(src)

add_subdirectory(tests)


add_test(NAME test1 COMMAND unit_tests)

