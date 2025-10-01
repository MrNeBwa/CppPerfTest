cmake_minimum_required(VERSION 3.10)
project(CppPerfTrack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(CppPerfTrack
    src/main.cpp
    src/Profiler.cpp
    src/JsonStorage.cpp
)
