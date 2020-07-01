cmake_minimum_required(VERSION 3.5)
project(Fizzbuzz LANGUAGES CXX)


add_subdirectory(src)

# Tests
# 	Not setting BUILD_TESTING as a command line argument is equivalent to use -DBUILD_TESTING=OFF
# 	To build tests, use -DBUILD_TESTING=ON
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# include(CTest) # call enable_testing() and turn BUILD_TESTING to ON by default (among other useful things)
	enable_testing()
	if(BUILD_TESTING)
		add_subdirectory(tests)
	endif()
endif()