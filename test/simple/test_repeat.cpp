// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/repeat.hpp"
#include "../../src/simple/size.hpp"

namespace {

TEST(repeat, nothing)
{
    vi32 result = nv::repeat(42, 0);
    EXPECT_EQ(size(result), 0);
}

TEST(repeat, twice)
{
    vi32 result = nv::repeat(42, 2);
    EXPECT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 42);
}

}
