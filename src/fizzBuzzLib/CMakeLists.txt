# fizzBuzz library
add_library(fizzBuzz
	include/fizzBuzz.h
	src/fizzBuzz.cpp
)
target_include_directories(fizzBuzz
	PUBLIC
		include/
)


target_compile_options(fizzBuzz
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)


# fizzBuzzProxy library
add_library(fizzBuzzProxy
	include/fizzBuzzProxy.h
	src/fizzBuzzProxy.cpp
)
target_include_directories(fizzBuzzProxy
	PUBLIC
		include/
)
target_compile_options(fizzBuzzProxy
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)