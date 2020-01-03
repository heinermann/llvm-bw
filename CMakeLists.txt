# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("llvm-bw")

# Include sub-projects.
add_subdirectory ("llvm-bw")
add_subdirectory ("chklib")
