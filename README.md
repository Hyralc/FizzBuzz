Fizz Buzz game :
	a first step to get started with :
	
	- Unit tests in C++
	- cmake : a generator of compilation scripts


Pre-requisite :

	- Boost.Test :
		You should get boost library installed on your computer.
		You can download version 1.72 from :
			https://www.boost.org/users/history/version_1_72_0.html
		Do not hesitate to download a newer version.
		Simply unpack it in any local directory.
	- cmake
	
Run cmake :

	- Create a directory named "build" next to <path-to-fizz-buzz-work-dir> / tests / src :
		<path-to-fizz-buzz-work-dir> / tests / build
	- cd <path-to-fizz-buzz-work-dir> / tests / build
	- run cmake command (caution : fill the cmd with your own boost library path) :
		cmake ../src -DFIZZBUZZ_ROOT=../../sources/fizzBuzzLib -DBOOST_PATH=path/to/boost_1_72_0

Then run the generated makefile.

	- On Windows, a .sln file could have been generated if Visual Studio has been spotted by cmake program.
	  In that case, just open it and run a build.

Remark :

	- Everything that is generated and built by actions described above can be thoroughly undone
	  by removing the content of the build directory.
		
		
	test2
