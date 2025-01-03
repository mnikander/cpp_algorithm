// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/gather.hpp"
#include "../../src/pipeline/scatter.hpp"
#include "../../src/pipeline/size.hpp"

namespace {

TEST(scatter, xpr)
{
    vc8 result = vc8{'A', 'B', 'C', 'D', 'E'} | xpr::scatter(vi32{2, 0, 1, 4, 3});

    EXPECT_EQ(result[0], 'B');
    EXPECT_EQ(result[1], 'C');
    EXPECT_EQ(result[2], 'A');
    EXPECT_EQ(result[3], 'E');
    EXPECT_EQ(result[4], 'D');
}

}
