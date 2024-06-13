#include <gtest/gtest.h>
#include "../../src/naive/rank.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(rank, primitive)
{
    EXPECT_EQ(rank('c'), 0);
    EXPECT_EQ(rank(1), 0);
    EXPECT_EQ(rank(1.0), 0);
}

TEST(rank, vector)
{
    EXPECT_EQ(rank(vc8{}), 1);
    EXPECT_EQ(rank(vi32{}), 1);
    EXPECT_EQ(rank(vf32{}), 1);
}

}
