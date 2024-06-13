#include <gtest/gtest.h>
#include <vector>
#include "../../src/naive/catenate.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/reverse.hpp"
#include "../../src/common.hpp"

namespace {

TEST(catenate, nothing)
{
    vi32 l{};
    vi32 r{};
    vi32 result = nv::catenate(l,r);
    ASSERT_EQ(size(result), 0);
}

TEST(catenate, palindrome)
{
    vi32 result = nv::catenate(nv::iota(3), nv::reverse(nv::iota(3)));
    ASSERT_EQ(size(result), 6);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 2);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[5], 0);
}

TEST(catenate, element_left)
{
    vi32 result = nv::catenate(42, nv::iota(5));
    ASSERT_EQ(nv::size(result), 6);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[3], 2);
    EXPECT_EQ(result[4], 3);
    EXPECT_EQ(result[5], 4);
}

TEST(catenate, element_right)
{
    vi32 result = nv::catenate(nv::iota(5), 42);
    ASSERT_EQ(nv::size(result), 6);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 3);
    EXPECT_EQ(result[4], 4);
    EXPECT_EQ(result[5], 42);
}

}
