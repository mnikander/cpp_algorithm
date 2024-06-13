#include <gtest/gtest.h>
#include "../../src/naive/drop.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(drop, nothing)
{
    vi32 result = drop(iota(0, 0), 0);
    ASSERT_EQ(size(result), 0);
}

TEST(drop, one)
{
    vi32 result = drop(iota(0, 1), 1);
    ASSERT_EQ(size(result), 0);
}

TEST(drop, two)
{
    vi32 result = drop(iota(5), 2);
    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
}

TEST(drop_last, nothing)
{
    vi32 result = drop_last(iota(0, 0), 0);
    ASSERT_EQ(size(result), 0);
}

TEST(drop_last, one)
{
    vi32 result = drop_last(iota(0, 1), 1);
    ASSERT_EQ(size(result), 0);
}

TEST(drop_last, two)
{
    vi32 data = iota(5);
    vi32 result = drop_last(data, 2);
    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
}

TEST(drop_last, two_fail)
{
    vi32 result = drop_last(iota(5), 2);
    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
}

}
