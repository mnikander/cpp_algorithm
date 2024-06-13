#include <gtest/gtest.h>
#include "../../src/naive/common.hpp"
#include "../../src/naive/iota.hpp"

namespace naive {

TEST(iota, nothing)
{
    vi32 result = iota(0, 0);
    EXPECT_EQ(result.size(), 0);
}

TEST(iota, one)
{
    vi32 result = iota(0, 1);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(iota, negative)
{
    vi32 result = iota(-1, 2);
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], -1);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 1);
}

TEST(iota, singleArgument0)
{
    vi32 result = iota(0);
    EXPECT_EQ(result.size(), 0);
}

TEST(iota, singleArgument2)
{
    vi32 result = iota(2);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
}

}
