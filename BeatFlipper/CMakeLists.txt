cmake_minimum_required(VERSION 3.24.2)
project(BeatFlipper)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(BeatFlipper Main.cpp Pobieraj.cpp Pobieraj.h OutputColors.cpp OutputColors.h ZmienneGlobalne.cpp ZmienneGlobalne.h)
