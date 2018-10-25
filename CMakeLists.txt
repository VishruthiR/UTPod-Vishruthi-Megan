cmake_minimum_required(VERSION 3.12)
project(UTPod-Vishruthi-Megan)

set(CMAKE_CXX_STANDARD 14)

add_executable(UTPOD driver.cpp
                     UTPOD.cpp
                     Song.cpp)