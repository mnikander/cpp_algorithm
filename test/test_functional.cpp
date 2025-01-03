// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include "../src/functional.hpp"

namespace {

TEST(functional, not)
{
    const auto f = nv::Not{};
    EXPECT_EQ(f(false), true);
}

TEST(functional, and)
{
    const auto f = nv::And{};
    EXPECT_EQ(f(false, true), false);
}

TEST(functional, or)
{
    const auto f = nv::Or{};
    EXPECT_EQ(f(false, true), true);
}

TEST(functional, identity)
{
    const auto f = nv::Identity{};
    EXPECT_EQ(f(5), 5);
}

TEST(functional, negate)
{
    const auto f = nv::Negate{};
    EXPECT_EQ(f(5), -5);
}

TEST(functional, plus)
{
    const auto f = nv::Plus{};
    EXPECT_EQ(f(4, 6), 10);
}

TEST(functional, minus)
{
    const auto f = nv::Minus{};
    EXPECT_EQ(f(4, 6), -2);
}

TEST(functional, times)
{
    const auto f = nv::Multiply{};
    EXPECT_EQ(f(4, 6), 24);
}

TEST(functional, divided)
{
    const auto f = nv::Divide{};
    EXPECT_EQ(f(12, 6), 2);
}

TEST(functional, modulo)
{
    const auto f = nv::Modulo{};
    EXPECT_EQ(f(12, 5), 2);
}

TEST(functional, power)
{
    const auto f = nv::Power{};
    EXPECT_EQ(f(2, 3), 8);
}

TEST(functional, minimum)
{
    const auto f = nv::Minimum{};
    EXPECT_EQ(f(4, 6), 4);
}

TEST(functional, maximum)
{
    const auto f = nv::Maximum{};
    EXPECT_EQ(f(4, 6), 6);
}

TEST(functional, equal)
{
    const auto f = nv::Equal{};
    EXPECT_EQ(f(4, 6), false);
}

TEST(functional, unequal)
{
    const auto f = nv::NotEqual{};
    EXPECT_EQ(f(4, 6), true);
}

TEST(functional, less)
{
    const auto f = nv::Less{};
    EXPECT_EQ(f(4, 6), true);
}

TEST(functional, less_equal)
{
    const auto f = nv::LessEqual{};
    EXPECT_EQ(f(4, 6), true);
}

TEST(functional, greater)
{
    const auto f = nv::Greater{};
    EXPECT_EQ(f(4, 6), false);
}

TEST(functional, greater_equal)
{
    const auto f = nv::GreaterEqual{};
    EXPECT_EQ(f(4, 6), false);
}

TEST(functional, least_common_multiple)
{
    const auto f = nv::LeastCommonMultiple{};
    EXPECT_EQ(f(4, 6), 12);
}

TEST(functional, greatest_common_divisor)
{
    const auto f = nv::GreatestCommonDivisor{};
    EXPECT_EQ(f(4, 6), 2);
}

// TEST(functional, foooo)
// {
//     const auto f = nv::foooo{};
//     EXPECT_EQ(f(4, 6), 12);
// }

}
