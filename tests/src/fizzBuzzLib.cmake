# Building library "fizzBuzz.lib" from fizzBuzz files files

message("")
message("........  Building fizzBuzz.lib  ........")
message("FIZZBUZZ_INCLUDE : ${FIZZBUZZ_INCLUDE}")
message("FIZZBUZZ_SRC : ${FIZZBUZZ_SRC}")


set(SOURCE_FILES
	${FIZZBUZZ_SRC}/fizzBuzz.cpp
	${FIZZBUZZ_SRC}/fizzBuzzProxy.cpp)


include_directories(${FIZZBUZZ_INCLUDE})

add_library(fizzBuzz ${SOURCE_FILES})

# Location where to build the lib
set_target_properties(fizzBuzz PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "libs")

message(".........................................")
message("")
