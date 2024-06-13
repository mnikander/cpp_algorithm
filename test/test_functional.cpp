#include <gtest/gtest.h>
#include "../src/functional.hpp"

namespace {

TEST(functional, dispatch)
{
    const auto f = meta::dispatch(meta::Identity{}, int());
    EXPECT_EQ(f(5), 5);

    const auto n = meta::dispatch(meta::Negate{}, int());
    EXPECT_EQ(n(5), -5);

    const auto add = meta::dispatch(meta::Plus{}, int());
    EXPECT_EQ(add(2,7), 9);
}

TEST(functional, logical_not)
{
    const auto f = meta::dispatch(xpr::logical_not(), int());
    EXPECT_EQ(f(false), true);
    EXPECT_EQ(xpr::logical_not(false), true);
}

TEST(functional, logical_and)
{
    const auto f = meta::dispatch(xpr::logical_and(), int());
    EXPECT_EQ(f(false, true), false);
    EXPECT_EQ(xpr::logical_and(false, true), false);
}

TEST(functional, logical_or)
{
    const auto f = meta::dispatch(xpr::logical_or(), int());
    EXPECT_EQ(f(false, true), true);
    EXPECT_EQ(xpr::logical_or(false, true), true);
}

TEST(functional, identity)
{
    const auto f = meta::dispatch(xpr::identity(), int());
    EXPECT_EQ(f(5), 5);
    EXPECT_EQ(xpr::identity(5), 5);
}

TEST(functional, negate)
{
    const auto f = meta::dispatch(xpr::negate(), int());
    EXPECT_EQ(f(5), -5);
    EXPECT_EQ(xpr::negate(5), -5);
}

TEST(functional, plus)
{
    const auto f = meta::dispatch(xpr::plus(), int());
    EXPECT_EQ(f(4, 6), 10);
    EXPECT_EQ(xpr::plus(4, 6), 10);
}

TEST(functional, minus)
{
    const auto f = meta::dispatch(xpr::minus(), int());
    EXPECT_EQ(f(4, 6), -2);
    EXPECT_EQ(xpr::minus(4, 6), -2);
}

TEST(functional, times)
{
    const auto f = meta::dispatch(xpr::times(), int());
    EXPECT_EQ(f(4, 6), 24);
    EXPECT_EQ(xpr::times(4, 6), 24);
}

TEST(functional, divided)
{
    const auto f = meta::dispatch(xpr::divided(), int());
    EXPECT_EQ(f(12, 6), 2);
    EXPECT_EQ(xpr::divided(12, 6), 2);
}

TEST(functional, power)
{
    const auto f = meta::dispatch(xpr::power(), int());
    EXPECT_EQ(f(2, 3), 8);
    EXPECT_EQ(xpr::power(2, 3), 8);
}

TEST(functional, min)
{
    const auto f = meta::dispatch(xpr::min(), int());
    EXPECT_EQ(f(4, 6), 4);
    EXPECT_EQ(xpr::min(4, 6), 4);
}

TEST(functional, max)
{
    const auto f = meta::dispatch(xpr::max(), int());
    EXPECT_EQ(f(4, 6), 6);
    EXPECT_EQ(xpr::max(4, 6), 6);
}

TEST(functional, equal)
{
    const auto f = meta::dispatch(xpr::equal(), int());
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::equal(4, 6), false);
}

TEST(functional, unequal)
{
    const auto f = meta::dispatch(xpr::unequal(), int());
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::unequal(4, 6), true);
}

TEST(functional, less)
{
    const auto f = meta::dispatch(xpr::less(), int());
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::less(4, 6), true);
}

TEST(functional, less_equal)
{
    const auto f = meta::dispatch(xpr::less_equal(), int());
    EXPECT_EQ(f(4, 6), true);
    EXPECT_EQ(xpr::less_equal(4, 6), true);
}

TEST(functional, greater)
{
    const auto f = meta::dispatch(xpr::greater(), int());
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::greater(4, 6), false);
}

TEST(functional, greater_equal)
{
    const auto f = meta::dispatch(xpr::greater_equal(), int());
    EXPECT_EQ(f(4, 6), false);
    EXPECT_EQ(xpr::greater_equal(4, 6), false);
}

TEST(functional, lcm)
{
    const auto f = meta::dispatch(xpr::least_common_multiple(), int());
    EXPECT_EQ(f(4, 6), 12);
    EXPECT_EQ(xpr::least_common_multiple(4, 6), 12);
}

TEST(functional, gcd)
{
    const auto f = meta::dispatch(xpr::greatest_common_divisor(), int());
    EXPECT_EQ(f(4, 6), 2);
    EXPECT_EQ(xpr::greatest_common_divisor(4, 6), 2);
}

// TEST(functional, foooo)
// {
//     const auto f = meta::dispatch(xpr::foooo(), int());
//     EXPECT_EQ(f(4, 6), 12);
//     EXPECT_EQ(xpr::foooo(4, 6), 12);
// }

}
