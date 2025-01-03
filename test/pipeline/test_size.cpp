// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/size.hpp"

namespace {

TEST(size, xpr_scalar)
{
    i32 result = 42 | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(size, xpr_vector)
{
    i32 result = vi32{0} | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(size, xpr_vector_empty)
{
    i32 result = vi32{} | xpr::size();
    EXPECT_EQ(result, 0);
}

}
