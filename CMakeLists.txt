# Tests
#	- Not setting BUILD_TESTING as a command line argument is equivalent to use -DBUILD_TESTING=OFF
#	  To build tests, use -DBUILD_TESTING=ON
#	- Finding boost.test can be done in two ways :
#		+ With a package handler (for examples apt-get on unbuntu or vcpkg on windows)
#		  To do this, set CMAKE_TOOLCHAIN_FILE as a command line argument.
#		+ By downloading, compiling and installing it
#		  To do this, set BUILD_DEPS to ON as a command line argument.
#	- To find boost.test, you must use one of these two ways : not setting CMAKE_TOOLCHAIN_FILE or BUILD_DEPS
#	  leads to an error. Note that the first has priority over the second in case you set both cache variables.
#
# Usage (with unit tests and boost.test to run tests) :
#	Configuration :
#	- with vcpkg for boost.test :
#		> cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_BUILD_TYPE=release -DCMAKE_TOOLCHAIN_FILE=${vcpkg_path}/scripts/buildsystems/vcpkg.cmake -DBUILD_TESTING=ON . -B build
#	- with boost.test installation from github
#		> cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_BUILD_TYPE=release -DBUILD_TESTING=ON -DBUILD_DEPS=ON . -B build
#	Build :
#		> cmake --build build --config Release
# 	Run unit tests :
#		> cd build
#		> ctest -C Release
#		> cd ..

cmake_minimum_required(VERSION 3.5)
project(Fizzbuzz LANGUAGES CXX)


if(CMAKE_TOOLCHAIN_FILE)
	set(BUILD_DEPS OFF)
endif()

add_subdirectory(src)

if(BUILD_TESTING)
	# include(CTest) # call enable_testing() and turn BUILD_TESTING to ON by default (among other useful things)
	enable_testing()
	
	if(BUILD_DEPS)
		# Setting CMAKE_PREFIX_PATH so that find_package(boost.test...) finds "${FizzBuzz current path}/ext" boost.test
		list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ext")
	endif()
	
	# Finds boost.test or builds boost.test from github 
	add_subdirectory(ext)
	
	add_subdirectory(tests)
endif()

# Only for running python tests (with pyTest) using CTest
# add_subdirectory(ctest-python)


message("*** CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message("*** python-tests : ${CMAKE_CURRENT_SOURCE_DIR}/ctest-python/python-tests")

enable_testing()

find_package(Python3 COMPONENTS Interpreter)

if(Python3_Interpreter_FOUND)
	add_test(
			NAME small-python-tests
			COMMAND Python3::Interpreter -m pytest -v -q test_small_python_tests.py
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ctest-python/python-tests"
			)
endif()
