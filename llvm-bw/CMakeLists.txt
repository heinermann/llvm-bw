# CMakeList.txt : CMake project for llvm-bw, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Add source to this project's executable.
add_executable (llvm-bw
                "llvm-bw.cpp"
                "IRReader.cpp"
                "IRReader.h"
                "BWMap.cpp"
                "BWMap.h"
                "IRLowering.cpp"
                "IRLowering.h"
                "TriggerLowering.cpp"
                "TriggerLowering.h"

                "BW/Offsets.h"
                "BW/Offsets.cpp"

                "TriggerTypes/DecoratedTrigger.h"
                "TriggerTypes/DecoratedTrigger.cpp"
                "TriggerTypes/FastVar.h"
                "TriggerTypes/FastVarReadOnly.h"
                "TriggerTypes/FastVarWriteOnly.h"
                "TriggerTypes/TriggerGenerator.h"
                "TriggerTypes/TriggerGenerator.cpp"

                "TriggerIR/Add.cpp"
                "TriggerIR/Add.h"
                "TriggerIR/Allocate.cpp"
                "TriggerIR/Allocate.h"
                "TriggerIR/AppInit.cpp"
                "TriggerIR/AppInit.h"
                "TriggerIR/Assign.cpp"
                "TriggerIR/Assign.h"
                "TriggerIR/BitwiseAnd.cpp"
                "TriggerIR/BitwiseAnd.h"
                "TriggerIR/BitwiseNot.cpp"
                "TriggerIR/BitwiseNot.h"
                "TriggerIR/BitwiseOr.cpp"
                "TriggerIR/BitwiseOr.h"
                "TriggerIR/BitwiseXor.cpp"
                "TriggerIR/BitwiseXor.h"
                "TriggerIR/Block.cpp"
                "TriggerIR/Block.h"
                "TriggerIR/Constant.cpp"
                "TriggerIR/Constant.h"
                "TriggerIR/Epilogue.cpp"
                "TriggerIR/Epilogue.h"
                "TriggerIR/Function.cpp"
                "TriggerIR/Function.h"
                "TriggerIR/Negate.cpp"
                "TriggerIR/Negate.h"
                "TriggerIR/NextPtr.cpp"
                "TriggerIR/NextPtr.h"
                "TriggerIR/Prologue.cpp"
                "TriggerIR/Prologue.h"
                "TriggerIR/ConstPtr.cpp"
                "TriggerIR/ConstPtr.h"
                "TriggerIR/Shl.cpp"
                "TriggerIR/Shl.h"
                "TriggerIR/Shr.cpp"
                "TriggerIR/Shr.h"
                "TriggerIR/StackAlloc.cpp"
                "TriggerIR/StackAlloc.h"
                "TriggerIR/Subtract.cpp"
                "TriggerIR/Subtract.h"
                "TriggerIR/TrigInst.cpp"
                "TriggerIR/TrigInst.h"
                "TriggerIR/Variable.cpp"
                "TriggerIR/Variable.h"
                "TriggerIR/Program.cpp"
                "TriggerIR/Program.h"

                "Exceptions/UnsupportedException.h"
                "Exceptions/NameConflictException.h"
                "Exceptions/MissingIdException.h"
               )

set_property(TARGET llvm-bw PROPERTY CXX_STANDARD 17)
target_compile_definitions(llvm-bw PRIVATE NOMINMAX STORMLIB_NO_AUTO_LINK)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(llvm-bw ${llvm_libs} MappingCoreLib IcuLib CommanderLib storm)

# TODO: Add tests and install targets if needed.
