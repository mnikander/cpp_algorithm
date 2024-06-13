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

}
