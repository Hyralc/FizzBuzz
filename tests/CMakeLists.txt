
#
# Create a target for executing the Boost unit tests.
#
 add_executable(unit_tests
 	fizzBuzzTests.cpp
 )
 

target_compile_definitions(unit_tests
    PRIVATE
        "BOOST_TEST_DYN_LINK=1"
)

# Indicates the link paths
 target_link_libraries(unit_tests
	fizzBuzz
	fizzBuzzProxy
	Boost::unit_test_framework
 )
 target_compile_options(unit_tests
 	PRIVATE
 		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
 			-Werror -Wall -Wextra>
 		$<$<CXX_COMPILER_ID:MSVC>:
 			/W4>
 )
 
 add_test(NAME test1 COMMAND unit_tests)