# CMakeList.txt : CMake project for llvm-bw, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory ("Chkdraft/StormLib")

# Add source to this project's executable.
add_library (MappingCoreLib STATIC
             "MappingCore.h"
             "Logger.h"
             "Chkdraft/MappingCoreLib/ArchiveFile.cpp"
             "Chkdraft/MappingCoreLib/ArchiveFile.h"
             "Chkdraft/MappingCoreLib/Basics.cpp"
             "Chkdraft/MappingCoreLib/Basics.h"
             "Chkdraft/MappingCoreLib/Buffer.cpp"
             "Chkdraft/MappingCoreLib/Buffer.h"
             "Chkdraft/MappingCoreLib/Chk.cpp"
             "Chkdraft/MappingCoreLib/Chk.h"
             "Chkdraft/MappingCoreLib/EscapeStrings.cpp"
             "Chkdraft/MappingCoreLib/EscapeStrings.h"
             "Chkdraft/MappingCoreLib/FileBrowser.cpp"
             "Chkdraft/MappingCoreLib/FileBrowser.h"
             "Chkdraft/MappingCoreLib/MapFile.cpp"
             "Chkdraft/MappingCoreLib/MapFile.h"
             "Chkdraft/MappingCoreLib/MappingCore.h"
             "Chkdraft/MappingCoreLib/MpqFile.cpp"
             "Chkdraft/MappingCoreLib/MpqFile.h"
             "Chkdraft/MappingCoreLib/Sc.cpp"
             "Chkdraft/MappingCoreLib/Sc.h"
             "Chkdraft/MappingCoreLib/ScData.cpp"
             "Chkdraft/MappingCoreLib/ScData.h"
             "Chkdraft/MappingCoreLib/Scenario.cpp"
             "Chkdraft/MappingCoreLib/Scenario.h"
             "Chkdraft/MappingCoreLib/Sections.cpp"
             "Chkdraft/MappingCoreLib/Sections.h"
             "Chkdraft/MappingCoreLib/StaticTrigComponentParser.cpp"
             "Chkdraft/MappingCoreLib/StaticTrigComponentParser.h"
             "Chkdraft/MappingCoreLib/SystemIO.cpp"
             "Chkdraft/MappingCoreLib/SystemIO.h"
             "Chkdraft/MappingCoreLib/TextTrigCompiler.cpp"
             "Chkdraft/MappingCoreLib/TextTrigCompiler.h"
             "Chkdraft/MappingCoreLib/TextTrigGenerator.cpp"
             "Chkdraft/MappingCoreLib/TextTrigGenerator.h"
             "Chkdraft/MappingCoreLib/readme.txt"
             "Chkdraft/MappingCoreLib/sha256.cpp"
             "Chkdraft/MappingCoreLib/sha256.h"
            )

file(GLOB iculib_src
     "Chkdraft/IcuLib/*.cpp"
     "Chkdraft/IcuLib/*.h"
     "Chkdraft/IcuLib/unicode/*.h"
    )

add_library(IcuLib STATIC
            ${iculib_src}
           )

add_library(CommanderLib STATIC
            "Logger.h"
            "Chkdraft/CommanderLib/CommandTypes.h"
            "Chkdraft/CommanderLib/Commander.cpp"
            "Chkdraft/CommanderLib/Commander.h"
            "Chkdraft/CommanderLib/ErrorHandler.cpp"
            "Chkdraft/CommanderLib/ErrorHandler.h"
            "Chkdraft/CommanderLib/GenericCommand.cpp"
            "Chkdraft/CommanderLib/GenericCommand.h"
            "Chkdraft/CommanderLib/Logger.cpp"
            "Chkdraft/CommanderLib/Logger.h"
            "Chkdraft/CommanderLib/TestCommands.cpp"
            "Chkdraft/CommanderLib/TestCommands.h"
            "Chkdraft/CommanderLib/Updater.cpp"
            "Chkdraft/CommanderLib/Updater.h"
           )

target_compile_definitions(MappingCoreLib PRIVATE NOMINMAX STORMLIB_NO_AUTO_LINK)
target_compile_definitions(IcuLib PRIVATE U_STATIC_IMPLEMENTATION U_COMMON_IMPLEMENTATION)

target_include_directories(MappingCoreLib
                           PRIVATE "Chkdraft/IcuLib/"
                          )

set_property(TARGET MappingCoreLib PROPERTY CXX_STANDARD 17)


# TODO: Add tests and install targets if needed.
