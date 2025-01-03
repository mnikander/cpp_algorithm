#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/all.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(all, empty_empty)
{
    vi32 l = {};
    vi32 r = {};

    // the predicate is true for all elements, because there are no elements
    EXPECT_TRUE(nv::all(l, nv::Equal{}, r));
}

TEST(all, one_empty)
{
    vi32 l = nv::iota(0);
    vi32 r = {};
    EXPECT_TRUE(nv::all(l, nv::Equal{}, r));
}

TEST(all, one)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    EXPECT_TRUE(nv::all(l, nv::Equal{}, r));
}

TEST(all, two)
{
    vi32 l = nv::iota(2);
    vi32 r = {0, 1};
    EXPECT_TRUE(nv::all(l, nv::Equal{}, r));
}

TEST(all, one_unequal)
{
    vi32 l = {0};
    vi32 r = {42};
    EXPECT_FALSE(nv::all(l, nv::Equal{}, r));
}

TEST(all, length_unequal)
{
    vi32 l = {0};
    vi32 r = {0, 1};
    EXPECT_FALSE(nv::all(l, nv::Equal{}, r));
}

TEST(all, predicate)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    const bool b = nv::all(l, std::equal_to<int>{}, r);
    EXPECT_TRUE(b);
}

TEST(all, predicate_int_float)
{
    constexpr f32 epsilon = 0.000001F;
    vi32 l = {0};
    vf32 r = {0.0F};
    auto feq = [epsilon](int i, float f)
    {
        const float fi = static_cast<float>(i);
        return (f - epsilon <= fi) && (fi <= f + epsilon);
    };
    const bool b = nv::all(l, feq, r);
    EXPECT_TRUE(b);
}

}
