// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/take.hpp"

namespace {

TEST(take, xpr)
{
    vi32 result = nv::iota(5) | xpr::take(2);
    ASSERT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
}

TEST(take_last, xpr)
{
    vi32 result = nv::iota(5) | xpr::take_last(2);
    ASSERT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);
}

}
