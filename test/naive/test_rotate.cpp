#include <gtest/gtest.h>
#include "../../src/naive/iota.hpp"
#include "../../src/naive/rotate.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(rotate, nothing)
{
    vi32 result = rotate(iota(0), 0);
    EXPECT_EQ(result.size(), 0);
}

TEST(rotate, one)
{
    vi32 result = rotate(iota(1));
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(rotate, fivePositive)
{
    vi32 result = rotate(iota(5), 2);
    EXPECT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 0);
    EXPECT_EQ(result[4], 1);
}

TEST(rotate, fiveNegative)
{
    vi32 result = rotate(iota(5), -2);
    EXPECT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 0);
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[4], 2);
}

TEST(rotate, fiveReverse)
{
    vi32 result = rotate(iota(5));
    EXPECT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[4], 0);
}

}
