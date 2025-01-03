#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/rotate.hpp"

namespace {

TEST(rotate, nothing)
{
    vi32 result = nv::rotate(nv::iota(0), 0);
    EXPECT_EQ(size(result), 0);
}

TEST(rotate, one)
{
    vi32 result = nv::rotate(nv::iota(1), 1);
    EXPECT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(rotate, two_of_five)
{
    vi32 result = nv::rotate(nv::iota(5), 2);
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 0);
    EXPECT_EQ(result[4], 1);
}

TEST(rotate_last, two_of_five)
{
    vi32 result = nv::rotate_last(nv::iota(5), 2);
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 0);
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[4], 2);
}

TEST(rotate, all)
{
    vi32 result = nv::rotate(nv::iota(5), 5);
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 3);
    EXPECT_EQ(result[4], 4);
}

}
