#include <gtest/gtest.h>
#include <vector>
#include "../src/functional.hpp"
#include "../src/iota.hpp"
#include "../src/none.hpp"
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

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

TEST(none, xpr)
{
    b8 a = vi32{0,0} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(a);

    b8 b = vi32{0,1} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(b);
    
    b8 c = vi32{1,0} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(c);

    b8 d = vi32{1,1} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_TRUE(d);
}

TEST(none, xpr_lambda)
{
    b8 a = vi32{0,0} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(a);

    b8 b = vi32{0,1} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(b);

    b8 c = vi32{1,0} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(c);

    b8 d = vi32{1,1} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_TRUE(d);
}

}
