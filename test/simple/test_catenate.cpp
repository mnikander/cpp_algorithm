// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/catenate.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/reverse.hpp"

namespace {

TEST(catenate, nothing)
{
    vi32 l{};
    vi32 r{};
    vi32 result = nv::catenate(l,r);
    ASSERT_EQ(size(result), 0);
}

TEST(catenate, vector_vector)
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

TEST(catenate, vector_element)
{
    vi32 result = nv::catenate(nv::iota(3), 42);
    ASSERT_EQ(nv::size(result), 4);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 42);
}

TEST(catenate, element_vector)
{
    vi32 result = nv::catenate(42, nv::iota(3));
    ASSERT_EQ(nv::size(result), 4);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[3], 2);
}

TEST(catenate, element_element)
{
    vi32 result = nv::catenate(13, 42);
    ASSERT_EQ(nv::size(result), 2);
    EXPECT_EQ(result[0], 13);
    EXPECT_EQ(result[1], 42);
}

}
