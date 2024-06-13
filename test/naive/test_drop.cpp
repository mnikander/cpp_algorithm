#include <gtest/gtest.h>
#include "../../src/naive/drop.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(drop, nothing)
{
    vi32 result = drop(iota(0, 0), 0);
    EXPECT_EQ(size(result), 0);
}

TEST(drop, one)
{
    vi32 result = drop(iota(0, 1), 1);
    EXPECT_EQ(size(result), 0);
}

TEST(drop, two)
{
    vi32 result = drop(iota(5), 2);
    EXPECT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
}

}
