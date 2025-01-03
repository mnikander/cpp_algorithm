#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/reverse.hpp"

namespace {

TEST(reverse, nothing)
{
    vi32 result = nv::reverse(nv::iota(0));
    EXPECT_EQ(size(result), 0);
}

TEST(reverse, one)
{
    vi32 result = nv::reverse(nv::iota(1));
    EXPECT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(reverse, five)
{
    vi32 result = nv::reverse(nv::iota(5));
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[4], 0);
}

}
