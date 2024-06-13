#include <gtest/gtest.h>
#include <vector>
#include "../src/equal.hpp"
#include "../src/iota.hpp"
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

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
    const bool b = nv::equal(l, std::equal_to<int>{}, r);
    EXPECT_TRUE(b);
}

TEST(equal, predicate_int_float)
{
    constexpr f32 epsilon = 0.000001F;
    vi32 l = {0};
    vf32 r = {epsilon};
    auto feq = [epsilon](int i, float f)
    {
        const float fi = static_cast<float>(i);
        return (f - epsilon <= fi) && (fi <= f + epsilon);
    };
    const bool b = nv::equal(l, feq, r);
    EXPECT_TRUE(b);
}

TEST(equal, xpr)
{
    b8 t = vi32{0,1} | xpr::equal(vi32{0,1});
    b8 f = vi32{0,0} | xpr::equal(vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

TEST(equal, xpr_lambda)
{
    b8 t = vi32{0,1} | xpr::equal([](int l, int r) { return l == r; }, vi32{0,1});
    b8 f = vi32{0,0} | xpr::equal([](int l, int r) { return l == r; }, vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

}
