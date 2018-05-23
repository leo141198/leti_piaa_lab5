cmake_minimum_required(VERSION 3.10)
project(piaa_lab5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(kmp src/kmp.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h)
add_executable(cycle_shift src/cycle_shift.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h)

add_executable(kmp_test test/kmp_test.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h test/KMPTest.h test/KMPTest.cpp)
add_executable(cycle_shift_test test/cycle_shift_test.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h test/KMPTest.h test/KMPTest.cpp)

add_executable(faster_algorithm test/faster_algorithm.cpp test/KMPTest.h test/KMPTest.cpp)

target_link_libraries(kmp_test gtest gtest_main)
target_link_libraries(cycle_shift_test gtest gtest_main)
target_link_libraries(faster_algorithm gtest gtest_main)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)