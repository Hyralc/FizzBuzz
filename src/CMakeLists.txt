
add_subdirectory(fizzBuzzLib)

#
# Create executable that uses .
#
add_executable(fizzbuzzCaller
	main.cpp
)
target_link_libraries(fizzbuzzCaller
	PRIVATE
		fizzBuzz
		fizzBuzzProxy
)

target_compile_options(fizzbuzzCaller
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)