// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/size.hpp"
#include "../../src/simple/zip.hpp"

namespace {

TEST(zip, nothing)
{
    vi32 nothing = nv::iota(0);
    auto result  = nv::zip(nothing, nothing);

    ASSERT_EQ(size(result), 0);
}

TEST(zip, five_five)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    auto result = nv::zip(alphabet, nv::iota(0, 5));
    
    ASSERT_EQ(size(result), 5);

    EXPECT_EQ(result[0], std::make_pair('A', 0));
    EXPECT_EQ(result[1], std::make_pair('B', 1));
    EXPECT_EQ(result[2], std::make_pair('C', 2));
    EXPECT_EQ(result[3], std::make_pair('D', 3));
    EXPECT_EQ(result[4], std::make_pair('E', 4));
}

TEST(zip, three_five)
{
    vc8 alphabet{'A', 'B', 'C'};
    auto result = nv::zip(alphabet, nv::iota(0, 5));

    ASSERT_EQ(size(result), 3);

    EXPECT_EQ(result[0], std::make_pair('A', 0));
    EXPECT_EQ(result[1], std::make_pair('B', 1));
    EXPECT_EQ(result[2], std::make_pair('C', 2));
}

TEST(zip, five_three)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    auto result = nv::zip(alphabet, nv::iota(0, 3));

    ASSERT_EQ(size(result), 3);

    EXPECT_EQ(result[0], std::make_pair('A', 0));
    EXPECT_EQ(result[1], std::make_pair('B', 1));
    EXPECT_EQ(result[2], std::make_pair('C', 2));
}

}
