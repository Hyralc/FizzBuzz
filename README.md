## Fizz Buzz game
A first step to get started with :

- Unit tests in C++
- cmake : a generator of compilation scripts


## Pre-requisite

### Boost.Test
Two ways to get **boost.test** library :
- you can download **boost.test** with package manager
- or you can choose to let cmake download and install **boost.test** while **fizzbuzz**'s cmake configuation step.

So, in more details :
- By package manager :
	- On Linux :
	``` bash
		$ sudo apt-get install libboost-all-dev
	```
	- On Windows, prefer using vcpkg, so you should have vcpkg installed on your machine.
	``` bash
		\> cd D:\path\to\your\vcpkg
		\> vcpkg install boost-test:x64-windows
	```
- By **cmake** : pay attention to the **fizzbuzz** configuration **cmake** step given below.

### cmake
Get a **cmake** of which version is > 3.5
	
## Building and testing
The following commands generate build files for **fizzbuzz** program, then build it and eventually run its unit tests.
In the process of installing **fizzbuzz**, the only command that differ over systems (Windows or linux) and **boost.test** installation strategies (using package manager or letting **cmake** do everything) is the **cmake** configuration step. All other commands are the same, no matter your system or your **boost.test** installation stategy :

``` bash
	$ cd /path/to/your/FizzBuzz/work/dir
	$ <cmake configuration step>
	$ cmake --build build [--config Release]
	$ cd build
	$ ctest -C Release|Debug
```
**Remarks** :
- As already said about package manager :
	- On linux (Ubuntu), we use native **apt-get**. 
	- On Windows, we use **vcpkg**. 
- There are 2 important variables about running unit tests when configuring with **cmake** : **BUILD_TESTING** and **BUILD_DEPS**.
- **BUILD_TESTING** : not given or turned to **OFF** as a command line argument of **cmake**, unit tests won't be compiled (you won't be able to run them). If turned to **ON**, cmake will try to compile unit tests program and find boost.test to link against it.
- **BUILD_DEPS** : if turned to **ON**, **cmake** will try to download boost.test and install it at configuration step.  

Let's look at the **cmake** depending on your system and choice for **boost.test** installation.
### On Linux
``` bash
	$ cmake -S . -B build -DCMAKE_CXX_FLAGS="-Werror" [-DCMAKE_BUILD_TYPE=Release] [-DBUILD_TESTING=ON] [-DBUILD_DEPS=ON]
```
### On Windows
Let **vcpkg_path** be the variable containing the absolute path to your vcpkg.
``` bash
	\> cmake -G "Visual Studio 16 2019" -A x64 [-DCMAKE_BUILD_TYPE=release] -DCMAKE_TOOLCHAIN_FILE=${vcpkg_path}/scripts/buildsystems/vcpkg.cmake [-DBUILD_TESTING=ON] [-DBUILD_DEPS=ON] . -B build
```

**Remark** :
- Most of the time, everything that is generated and built by actions described above can be thoroughly undone by removing the content of the build directory.
- There is an exception though : if you choose to let cmake download **boost.test** for unit tests, you have to remove **boost.test** as well. To do that, remove the following directory :
``` bash
	${path-to-your-FizzBuzz-work-dir}/ext/boost
```