cmake_minimum_required(VERSION 3.12)

project(cpp_algorithm)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link unit_tests with what we want to test and the GTest and pthread library
add_executable(unit_tests test/main.cpp
                          test/meta/test_result.cpp
                          test/test_arithmetic.cpp
                          test/test_catenate.cpp
                          test/test_drop.cpp
                          test/test_equal.cpp
                          test/test_filter.cpp
                          test/test_gather.cpp
                          test/test_grade.cpp
                          test/test_iota.cpp
                          test/test_map.cpp
                          test/test_reduce.cpp
                          test/test_repeat.cpp
                          test/test_reverse.cpp
                          test/test_rank.cpp
                          test/test_rotate.cpp
                          test/test_scatter.cpp
                          test/test_size.cpp
                          test/test_take.cpp
                          test/test_xpr_pipe.cpp
)
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)

add_executable(main src/_main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
