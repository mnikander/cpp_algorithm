#include <gtest/gtest.h>
#include "../../src/naive/repeat.hpp"

namespace naive {

TEST(repeat, nothing)
{
    auto result = repeat(42, 0);
    EXPECT_EQ(result.size(), 0);
}

TEST(repeat, twice)
{
    auto result = repeat(42, 2);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 42);
}

}
