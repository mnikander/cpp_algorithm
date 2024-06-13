#include <gtest/gtest.h>
#include "../src/functional.hpp"

namespace {

TEST(functional, dispatch)
{
    const auto f = meta::dispatch(xpr::Identity{}, int());
    EXPECT_EQ(f(5), 5);

    const auto n = meta::dispatch(xpr::Negate{}, int());
    EXPECT_EQ(n(5), -5);

    const auto add = meta::dispatch(xpr::Plus{}, int());
    EXPECT_EQ(add(2,7), 9);
}

}
