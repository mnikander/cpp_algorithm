#include <gtest/gtest.h>
#include <vector>
#include "../src/all.hpp"
#include "../src/functional.hpp"
#include "../src/iota.hpp"
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

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

TEST(all, xpr)
{
    b8 t = vi32{0,1} | xpr::all(nv::Equal{}, vi32{0,1});
    b8 f = vi32{0,0} | xpr::all(nv::Equal{}, vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

TEST(all, xpr_lambda)
{
    b8 t = vi32{0,1} | xpr::all([](int l, int r) { return l == r; }, vi32{0,1});
    b8 f = vi32{0,0} | xpr::all([](int l, int r) { return l == r; }, vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

}
