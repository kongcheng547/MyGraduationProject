cmake_minimum_required(VERSION 3.21)
project(StepReader)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(Debug)
include_directories(StepReader)

add_executable(StepReader
        .idea/.gitignore
        .idea/modules.xml
        .idea/StepReader.iml
        .idea/vcs.xml
        .idea/workspace.xml
        Debug/StepReader.exe
        Debug/StepReader.pdb
        StepReader/Debug/StepReader.tlog/CL.command.1.tlog
        StepReader/Debug/StepReader.tlog/CL.read.1.tlog
        StepReader/Debug/StepReader.tlog/CL.write.1.tlog
        StepReader/Debug/StepReader.tlog/link.command.1.tlog
        StepReader/Debug/StepReader.tlog/link.read.1.tlog
        StepReader/Debug/StepReader.tlog/link.write.1.tlog
        StepReader/Debug/StepReader.tlog/StepReader.lastbuildstate
        StepReader/Debug/main.obj
        StepReader/Debug/StepReader.exe.recipe
        StepReader/Debug/StepReader.ilk
        StepReader/Debug/StepReader.log
        StepReader/Debug/vc142.idb
        StepReader/Debug/vc142.pdb
        StepReader/main.cpp
        StepReader/StepReader.vcxproj
        StepReader/StepReader.vcxproj.filters
        StepReader/StepReader.vcxproj.user
        StepReader.sln)
