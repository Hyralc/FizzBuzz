
#
# Create a target for executing the Boost unit tests.
#
 add_executable(unit_tests
 	fizzBuzzTests.cpp
 )
 # No need to add linked libraries include directories (see the further link instruction),
 # since they are PUBLIC on that matter.
 target_include_directories(unit_tests
    PRIVATE
        ${Boost_INCLUDE_DIRS}
 )

target_compile_definitions(unit_tests
    PRIVATE
        "BOOST_TEST_DYN_LINK=1"
)
# Indicates the link paths
 target_link_libraries(unit_tests
	fizzBuzz
	fizzBuzzProxy
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 )
 target_compile_options(unit_tests
 	PRIVATE
 		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
 			-Werror -Wall -Wextra>
 		$<$<CXX_COMPILER_ID:MSVC>:
 			/W4>
 )