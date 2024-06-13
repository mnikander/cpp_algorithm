#include <gtest/gtest.h>
#include "../src/functional.hpp"

namespace {

TEST(functional, logical_not)
{
    const auto f = nv::LogicalNot{};
    EXPECT_EQ(f(false), true);
    EXPECT_EQ(xpr::logical_not(false), true);
}

TEST(functional, logical_and)
{
    const auto f = nv::LogicalAnd{};
    EXPECT_EQ(f(false, true), false);
    EXPECT_EQ(xpr::logical_and(false, true), false);
}

TEST(functional, logical_or)
{
    const auto f = nv::LogicalOr{};
    EXPECT_EQ(f(false, true), true);
    EXPECT_EQ(xpr::logical_or(false, true), true);
}

TEST(functional, identity)
{
    const auto f = nv::Identity{};
    EXPECT_EQ(f(5), 5);
    EXPECT_EQ(xpr::identity(5), 5);
}

TEST(functional, negate)
{
    const auto f = nv::Negate{};
    EXPECT_EQ(f(5), -5);
    EXPECT_EQ(xpr::negate(5), -5);
}

TEST(functional, plus)
{
    const auto f = nv::Plus{};
    EXPECT_EQ(f(4, 6), 10);
    EXPECT_EQ(xpr::plus(4, 6), 10);
}

TEST(functional, minus)
{
    const auto f = nv::Minus{};
    EXPECT_EQ(f(4, 6), -2);
    EXPECT_EQ(xpr::minus(4, 6), -2);
}

TEST(functional, times)
{
    const auto f = nv::Times{};
    EXPECT_EQ(f(4, 6), 24);
    EXPECT_EQ(xpr::times(4, 6), 24);
}

TEST(functional, divided)
{
    const auto f = nv::Divided{};
    EXPECT_EQ(f(12, 6), 2);
    EXPECT_EQ(xpr::divided(12, 6), 2);
}

TEST(functional, power)
{
    const auto f = nv::Power{};
    EXPECT_EQ(f(2, 3), 8);
    EXPECT_EQ(xpr::power(2, 3), 8);
}

TEST(functional, min)
{
    const auto f = nv::Min{};
    EXPECT_EQ(f(4, 6), 4);
    EXPECT_EQ(xpr::min(4, 6), 4);
}

TEST(functional, max)
{
    const auto f = nv::Max{};
    EXPECT_EQ(f(4, 6), 6);
    EXPECT_EQ(xpr::max(4, 6), 6);
}

TEST(functional, equal)
{
    const auto f = nv::Equal{};
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::equal(4, 6), false);
}

TEST(functional, unequal)
{
    const auto f = nv::Unequal{};
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::unequal(4, 6), true);
}

TEST(functional, less)
{
    const auto f = nv::Less{};
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::less(4, 6), true);
}

TEST(functional, less_equal)
{
    const auto f = nv::LessEqual{};
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::less_equal(4, 6), true);
}

TEST(functional, greater)
{
    const auto f = nv::Greater{};
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::greater(4, 6), false);
}

TEST(functional, greater_equal)
{
    const auto f = nv::GreaterEqual{};
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::greater_equal(4, 6), false);
}

TEST(functional, least_common_multiple)
{
    const auto f = nv::LeastCommonMultiple{};
    EXPECT_EQ(f(4, 6), 12);
    EXPECT_EQ(xpr::least_common_multiple(4, 6), 12);
}

TEST(functional, greatest_common_divisor)
{
    const auto f = nv::GreatestCommonDivisor{};
    EXPECT_EQ(f(4, 6), 2);
    EXPECT_EQ(xpr::greatest_common_divisor(4, 6), 2);
}

// TEST(functional, foooo)
// {
//     const auto f = nv::foooo{};
//     EXPECT_EQ(f(4, 6), 12);
//     EXPECT_EQ(xpr::foooo(4, 6), 12);
// }

}
