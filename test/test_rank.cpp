#include <gtest/gtest.h>
#include "../src/rank.hpp"
#include "../src/meta/global_datatypes.hpp"

namespace {

TEST(rank, primitive)
{
    EXPECT_EQ(nv::rank('c'), 0);
    EXPECT_EQ(nv::rank(1), 0);
    EXPECT_EQ(nv::rank(1.0), 0);
}

TEST(rank, vector)
{
    EXPECT_EQ(nv::rank(vc8{}), 1);
    EXPECT_EQ(nv::rank(vi32{}), 1);
    EXPECT_EQ(nv::rank(vf32{}), 1);
}

}
