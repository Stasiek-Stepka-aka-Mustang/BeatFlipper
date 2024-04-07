cmake_minimum_required(VERSION 3.24.2)
project(BeatFlipper)

set(CMAKE_CXX_STANDARD 23)

#[[ TU JEST SECRET SAUCE, ŻEBY DZIAŁAŁO! ]]
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ld_classic")

add_executable(BeatFlipper Main.cpp Download.cpp Download.h OutputColors.cpp OutputColors.h GlobalVariables.cpp GlobalVariables.h
        Download.cpp)


#[[
set(CMAKE_EXE_LINKER_FLAGS "-static")
]]
#[[
set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE INTERNAL "" FORCE)]]
