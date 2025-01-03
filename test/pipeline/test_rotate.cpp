// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/rotate.hpp"

namespace {

TEST(rotate, xpr)
{
    vi32 result = xpr::iota(5) | xpr::rotate(2);
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 0);
    EXPECT_EQ(result[4], 1);
}

TEST(rotate_last, xpr)
{
    vi32 result = xpr::iota(5) | xpr::rotate_last(2);
    EXPECT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 0);
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[4], 2);
}

}
