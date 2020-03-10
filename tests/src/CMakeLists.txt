

# Command to run from path/to/repo-fizzbuzz/tests/build
# > cmake ../src -DFIZZBUZZ_ROOT=../../sources/fizzBuzzLib -DBOOST_PATH=path/to/boost_1_72_0
# Example :
# > cmake ../src -DFIZZBUZZ_ROOT=../../sources/fizzBuzzLib -DBOOST_PATH=../../../../boost_1_72_0

cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(fizzBuzzTests VERSION 1.0)

message("** FIZZBUZZ_ROOT : ${FIZZBUZZ_ROOT}")
message("** BOOST_PATH : ${BOOST_PATH}")

# Path to source files to be tested
if ("${FIZZBUZZ_ROOT}" STREQUAL "")
	message("Argument FIZZBUZZ_ROOT is missing.")
	return()
endif()

if(NOT IS_DIRECTORY "${FIZZBUZZ_ROOT}")
	message("${FIZZBUZZ_ROOT} is NOT a directory.")
endif()


# Path to Boost
if ("${BOOST_PATH}" STREQUAL "")
	message("Argument BOOST_PATH is missing.")
	return()
endif()

if(NOT IS_DIRECTORY "${BOOST_PATH}")
	message("${BOOST_PATH} is NOT a directory.")
endif()

# return()

message("---------------------")
message("SOME USEFUL VARIABLES")
message("---------------------")
message(" ** CMAKE_BUILD_TYPE : ${CMAKE_BUILD_TYPE}")
message(" ** PROCESSOR_ARCHITECTURE : ${PROCESSOR_ARCHITECTURE}")
message(" ** CMAKE_HOST_SYSTEM_VERSION : ${CMAKE_HOST_SYSTEM_VERSION}")
message(" ** CMAKE_HOST_SYSTEM_NAME : ${CMAKE_HOST_SYSTEM_NAME}")
message(" ** CMAKE_HOST_SYSTEM_PROCESSOR : ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(" ** CMAKE_HOST_SYSTEM : ${CMAKE_HOST_SYSTEM}")
message(" ** CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")
message(" ** CMAKE_SYSTEM_PROCESSOR : ${CMAKE_SYSTEM_PROCESSOR}")
message(" ** CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE : ${CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE}")
message(" ** CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")
message(" ** PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}")
message(" ** CMAKE_PROJECT_NAME : ${CMAKE_PROJECT_NAME}")
message(" ** CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message("---------------------")



set(FIZZBUZZ_INCLUDE "${FIZZBUZZ_ROOT}/include")
set(FIZZBUZZ_SRC "${FIZZBUZZ_ROOT}/src")


include("fizzBuzzLib.cmake")
 

# return()

set(PATH_TO_BOOST_HEADERS "${BOOST_PATH}")
include_directories(${PATH_TO_BOOST_HEADERS})

link_directories(${PROJECT_BINARY_DIR}/libs)
add_executable(fizzBuzzTests fizzBuzzTests.cpp)
target_link_libraries(fizzBuzzTests "fizzBuzz.lib")
