## Fizz Buzz game
A first step to get started with :

- Unit tests in C++
- cmake : a generator of compilation scripts


## Pre-requisite

- **Boost.Test** : You should get boost library installed on your computer.
	- On Linux :
	``` bash
		$ sudo apt-get install libboost-all-dev
	```
	- On Windows, prefer using vcpkg, so you should have vcpkg installed on your machine.
	``` bash
		\> cd D:\path\to\your\vcpkg
		\> vcpkg install boost-test:x64-windows
	```
- **cmake** (version > 3.5)
	
## Building and testing
The following commands generate build files for fizzbuzz program, then build it and eventually run its unit tests.
### On Linux
``` bash
	$ cd /path/your/FizzBuzz/Repo
	$ cmake -S . -B build -DCMAKE_CXX_FLAGS="-Werror"
	$ cmake --build build
	$ cd build && ctest
```
### On Windows
``` bash
	\> cd D:\path\your\FizzBuzz\Repo
	\> cmake -G "Visual Studio 16 2019" -A x64 [-DCMAKE_BUILD_TYPE=release] -DCMAKE_TOOLCHAIN_FILE=${vcpkg_path}/scripts/buildsystems/vcpkg.cmake . -B build
```
Then make the build with your visual studio. Indeed, if you run :
``` bash
	\> cmake --build build
```
builds only in debug mode and does not take release mode into account.
Then run unit tests by typing : 
``` bash
	\> cd build
	\> ctest -C Release
```

**Remark** : Everything that is generated and built by actions described above can be thoroughly undone by removing the content of the build directory.