cmake_minimum_required(VERSION 3.12)

project(cpp_algorithm)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES )

# Link unit_tests with what we want to test and the GTest and pthread library
add_executable(unit_tests ${SOURCES}
                          test/main.cpp
                          test/meta/test_result.cpp

                          test/pipeline/test_all.cpp
                          test/pipeline/test_any.cpp
                          test/pipeline/test_catenate.cpp
                          test/pipeline/test_drop.cpp
                          test/pipeline/test_filter.cpp
                          test/pipeline/test_gather.cpp
                          test/pipeline/test_grade.cpp
                          test/pipeline/test_iota.cpp
                          test/pipeline/test_map.cpp
                          test/pipeline/test_none.cpp
                          test/pipeline/test_reduce.cpp
                          test/pipeline/test_repeat.cpp
                          test/pipeline/test_reverse.cpp
                          test/pipeline/test_rank.cpp
                          test/pipeline/test_rotate.cpp
                          test/pipeline/test_scatter.cpp
                          test/pipeline/test_size.cpp
                          test/pipeline/test_take.cpp
                          test/pipeline/test_xpr_pipe.cpp

                          test/simple/test_all.cpp
                          test/simple/test_any.cpp
                          test/simple/test_catenate.cpp
                          test/simple/test_drop.cpp
                          test/simple/test_filter.cpp
                          test/simple/test_gather.cpp
                          test/simple/test_grade.cpp
                          test/simple/test_iota.cpp
                          test/simple/test_map.cpp
                          test/simple/test_none.cpp
                          test/simple/test_reduce.cpp
                          test/simple/test_repeat.cpp
                          test/simple/test_reverse.cpp
                          test/simple/test_rank.cpp
                          test/simple/test_rotate.cpp
                          test/simple/test_scatter.cpp
                          test/simple/test_shuffle.cpp
                          test/simple/test_size.cpp
                          test/simple/test_take.cpp
                          test/simple/test_zip.cpp

                          test/test_functional.cpp
)
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)

add_executable(main src/_main.cpp ${SOURCES})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
