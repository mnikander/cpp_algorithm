#include <gtest/gtest.h>
#include "../src/iota.hpp"
#include "../src/datatype_aliases.hpp"

namespace {

TEST(iota, nothing)
{
    vi32 result = nv::iota(0, 0);
    EXPECT_EQ(size(result), 0);
}

TEST(iota, one)
{
    vi32 result = nv::iota(0, 1);
    EXPECT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 0);
}

TEST(iota, negative)
{
    vi32 result = nv::iota(-1, 2);
    EXPECT_EQ(size(result), 3);
    EXPECT_EQ(result[0], -1);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 1);
}

TEST(iota, singleArgument0)
{
    vi32 result = nv::iota(0);
    EXPECT_EQ(size(result), 0);
}

TEST(iota, singleArgument2)
{
    vi32 result = nv::iota(2);
    EXPECT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
}

}
