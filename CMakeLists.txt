cmake_minimum_required(VERSION 3.5)
project(Fizzbuzz LANGUAGES CXX)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
   include(CTest)
   add_subdirectory(tests)
endif()
