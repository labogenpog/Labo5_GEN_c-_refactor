# cmake_minimum_required(VERSION <specify CMake version here>)

cmake_minimum_required(VERSION 3.3)

project(Labo5_C___refactor)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_subdirectory(src)
add_subdirectory(test)

add_executable(Labo5_C___refactor
        src/Customer.cpp
        src/Customer.h
        src/main.cpp
        src/Movie.cpp
        src/Movie.h
        src/Rental.h)

#add_executable(runUnitTests gtest.cpp ${test_SRCS})