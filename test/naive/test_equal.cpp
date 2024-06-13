#include <gtest/gtest.h>
#include <vector>
#include "../../src/naive/equal.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/size.hpp"
#include "../../src/common.hpp"

namespace {

TEST(equal, none)
{
    vi32 l = nv::iota(0);
    vi32 r = {};
    EXPECT_TRUE(nv::equal(l, r));
}

TEST(equal, one)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    EXPECT_TRUE(nv::equal(l, r));
}

TEST(equal, two)
{
    vi32 l = nv::iota(2);
    vi32 r = {0, 1};
    EXPECT_TRUE(nv::equal(l, r));
}

TEST(equal, one_unequal)
{
    vi32 l = {0};
    vi32 r = {42};
    EXPECT_FALSE(nv::equal(l, r));
}

TEST(equal, length_unequal)
{
    vi32 l = {0};
    vi32 r = {0, 1};
    EXPECT_FALSE(nv::equal(l, r));
}

TEST(equal, predicate)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    const bool b = nv::equal(l, r, std::equal_to<int>{});
    EXPECT_TRUE(b);
}

TEST(equal, predicate_int_float)
{
    constexpr f32 epsilon = 0.000001F;
    vi32 l = {0};
    vf32 r = {epsilon};
    const bool b = nv::equal(l, r, [epsilon](int i, float f){
        const float fi = static_cast<float>(i);
        return (f - epsilon <= fi) && (fi <= f + epsilon); });
    EXPECT_TRUE(b);
}

}
