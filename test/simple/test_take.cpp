#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/take.hpp"

namespace {

TEST(take, nothing)
{
    vi32 result = nv::take(nv::iota(0, 0), 0);
    ASSERT_EQ(size(result), 0);
}

TEST(take, one)
{
    vi32 result = nv::take(nv::iota(0, 1), 1);
    ASSERT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(take, two)
{
    vi32 result = nv::take(nv::iota(5), 2);
    ASSERT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
}

TEST(take_last, nothing)
{
    vi32 result = nv::take_last(nv::iota(0, 0), 0);
    ASSERT_EQ(size(result), 0);
}

TEST(take_last, one)
{
    vi32 result = nv::take_last(nv::iota(0, 1), 1);
    ASSERT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(take_last, two)
{
    vi32 result = nv::take_last(nv::iota(10), 2);
    ASSERT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 8);
    EXPECT_EQ(result[1], 9);
}

}
