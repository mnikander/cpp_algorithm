cmake_minimum_required(VERSION 3.12)

project(cpp_algorithm)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link unit_tests with what we want to test and the GTest and pthread library
add_executable(unit_tests test/main.cpp
                          test/meta/test_result.cpp
                          test/naive/test_arithmetic.cpp
                          test/naive/test_catenate.cpp
                          test/naive/test_iota.cpp
                          test/naive/test_reduce.cpp
                          test/naive/test_repeat.cpp
                          test/naive/test_reverse.cpp
                          test/naive/test_rotate.cpp
                          test/naive/test_take.cpp
)
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)
