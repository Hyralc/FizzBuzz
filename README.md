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
Let **vcpkg_path** be the variable containing the absolute path to your vcpkg.
``` bash
	\> cd D:\path\your\FizzBuzz\Repo
	\> cmake -G "Visual Studio 16 2019" -A x64 [-DCMAKE_BUILD_TYPE=release] -DCMAKE_TOOLCHAIN_FILE=${vcpkg_path}/scripts/buildsystems/vcpkg.cmake . -B build
	\> cmake --build build [--config Release]
	\> cd build
	\> ctest
```

**Remark** : Everything that is generated and built by actions described above can be thoroughly undone by removing the content of the build directory.