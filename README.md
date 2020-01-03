## Dependencies
- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/)
- LLVM (see subsection, install cmake first)
- CLang

### Windows

#### Installing LLVM
We need to do it from source to inclue the proper CMake, header, and library files which are otherwise not included in the downloadable installer.

1. `git clone git@github.com:llvm/llvm-project.git`
2. `cd llvm-project`
3. `git checkout llvmorg-9.0.1`
2. Open an administrator command line in that directory
3. Run the following commands:
  1. `mkdir build`
  2. `cd build`
  3. `cmake -Thost=x64 ../llvm`
  4. `cmake --build . --target install`
4. Wait 100000000 years for it to build.
5. Reboot your system.


### Linux
TODO

## Building
Once you've sorted out the dependencies, use the following commands. Alternative on Windows you can open the Visual Studio solution file and switch to the CMake targets or directory view in the solution explorer and build from there.

### Run Once
1. `mkdir build`
2. `cd build`
3. `cmake ../`

### Repeat for each build
`cmake --build .`

## Using
1. Use CLang to compile a C++ or other language to LLVM IR with `clang++ -S -emit-llvm test.cpp`.
2. Run `llvm-bw test.ll out.chk`.
