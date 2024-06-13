#include <gtest/gtest.h>
#include <vector>
#include "../../src/naive/catenate.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/reverse.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(catenate, nothing)
{
    vi32 l{};
    vi32 r{};
    vi32 result = catenate(l,r);
    EXPECT_EQ(result.size(), 0);
}

TEST(catenate, palindrome)
{
    vi32 result = catenate(iota(3), reverse(iota(3)));
    EXPECT_EQ(result.size(), 6);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 2);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[5], 0);
}

}