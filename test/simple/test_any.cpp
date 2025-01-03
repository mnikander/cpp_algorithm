// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/any.hpp"
#include "../../src/simple/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(any, empty_empty)
{
    vi32 l = {};
    vi32 r = {};

    // there aren't any elements for which the predicate is true, because there aren't any elements
    EXPECT_FALSE(nv::any(l, nv::Equal{}, r));
}

TEST(any, one_empty)
{
    vi32 l = nv::iota(0);
    vi32 r = {};
    EXPECT_FALSE(nv::any(l, nv::Equal{}, r));
}

TEST(any, one)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    EXPECT_TRUE(nv::any(l, nv::Equal{}, r));
}

TEST(any, two)
{
    vi32 l = nv::iota(2);
    vi32 r = {0, 1};
    EXPECT_TRUE(nv::any(l, nv::Equal{}, r));
}

TEST(any, one_unequal)
{
    vi32 l = {0};
    vi32 r = {42};
    EXPECT_FALSE(nv::any(l, nv::Equal{}, r));
}

TEST(any, length_unequal)
{
    vi32 l = {0};
    vi32 r = {0, 1};
    EXPECT_TRUE(nv::any(l, nv::Equal{}, r));
}

TEST(any, predicate)
{
    vi32 l = nv::iota(1);
    vi32 r = {0};
    const bool b = nv::any(l, std::equal_to<int>{}, r);
    EXPECT_TRUE(b);
}

TEST(any, predicate_int_float)
{
    constexpr f32 epsilon = 0.000001F;
    vi32 l = {0};
    vf32 r = {0.0F};
    auto feq = [epsilon](int i, float f)
    {
        const float fi = static_cast<float>(i);
        return (f - epsilon <= fi) && (fi <= f + epsilon);
    };
    const bool b = nv::any(l, feq, r);
    EXPECT_TRUE(b);
}

}
