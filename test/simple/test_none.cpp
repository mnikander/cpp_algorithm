#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/none.hpp"
#include "../../src/simple/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(none, empty_empty)
{
    vi32 l = {};
    vi32 r = {};

    // there are NO elements for which the predicate is true, because there are no elements
    EXPECT_TRUE(nv::none(l, nv::Equal{}, r));
}

TEST(none, one_empty)
{
    vi32 l = nv::iota(0);
    vi32 r = {};
    EXPECT_TRUE(nv::none(l, nv::Equal{}, r));
}

TEST(none, one)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    EXPECT_FALSE(nv::none(l, nv::Equal{}, r));
}

TEST(none, two)
{
    vi32 l = nv::iota(2);
    vi32 r = {0, 1};
    EXPECT_FALSE(nv::none(l, nv::Equal{}, r));
}

TEST(none, one_unequal)
{
    vi32 l = {0};
    vi32 r = {42};
    EXPECT_TRUE(nv::none(l, nv::Equal{}, r));
}

TEST(none, length_unequal)
{
    vi32 l = {0};
    vi32 r = {0, 1};
    EXPECT_FALSE(nv::none(l, nv::Equal{}, r));
}

TEST(none, predicate)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    const bool b = nv::none(l, std::equal_to<int>{}, r);
    EXPECT_FALSE(b);
}

TEST(none, predicate_int_float)
{
    constexpr f32 epsilon = 0.000001F;
    vi32 l = {0};
    vf32 r = {0.0F};
    auto feq = [epsilon](int i, float f)
    {
        const float fi = static_cast<float>(i);
        return (f - epsilon <= fi) && (fi <= f + epsilon);
    };
    const bool b = nv::none(l, feq, r);
    EXPECT_FALSE(b);
}

}
