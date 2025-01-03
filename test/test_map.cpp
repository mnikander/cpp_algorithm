#include <gtest/gtest.h>
#include <functional>
#include "../src/meta/global_datatypes.hpp"
#include "../src/iota.hpp"
#include "../src/functional.hpp"
#include "../src/map.hpp"
#include "../src/reverse.hpp"

namespace {

TEST(map, unary_identity)
{
    vi32 data   = nv::iota(5);
    vi32 result = nv::map(data, [](int i){ return i; });

    ASSERT_EQ(size(data), size(result));
    EXPECT_EQ(data, result);
}

TEST(map, unary_squared)
{
    vi32 data   = nv::iota(5);
    vi32 result = nv::map(data, [](int i){ return i*i; });

    ASSERT_EQ(size(data), size(result));
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 9);
    EXPECT_EQ(result[4], 16);
}

TEST(map, unary_int_to_float)
{
    vf32 result = nv::map(vi32{-1, 0, 1}, [](int i){ return static_cast<f32>(i); });

    ASSERT_EQ(size(result), 3);
    EXPECT_FLOAT_EQ(result[0], -1.0F);
    EXPECT_FLOAT_EQ(result[1],  0.0F);
    EXPECT_FLOAT_EQ(result[2],  1.0F);
}

TEST(map, scalar_scalar)
{
    i32 result = nv::map(10, std::plus<int>{}, 3);

    EXPECT_EQ(result, 13);
}

TEST(map, scalar_vector)
{
    vi32 result = nv::map(10, std::plus<int>{}, nv::iota(3));

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
    EXPECT_EQ(result[2], 12);
}

TEST(map, vector_scalar)
{
    vi32 result = nv::map(nv::iota(3), std::plus<int>{}, 10);

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
    EXPECT_EQ(result[2], 12);
}

TEST(map, vector_vector)
{
    vi32 result = nv::map(nv::iota(3), std::plus<int>{}, nv::reverse(nv::iota(3)));

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 2);
}

TEST(map, vector_vector_functional)
{
    vi32 result = nv::map(nv::iota(3), nv::Plus{}, nv::reverse(nv::iota(3)));

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 2);
}

TEST(map, xpr_vector)
{
    vi32 result = xpr::iota(5) | xpr::map([](int i){ return i*i; });

    ASSERT_EQ(size(result), size(result));
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 9);
    EXPECT_EQ(result[4], 16);
}

TEST(map, xpr_scalar_scalar)
{
    i32 result = 2 | xpr::map(nv::Plus{}, 3);
    EXPECT_EQ(result, 5);
}

TEST(map, xpr_scalar_vector)
{
    vi32 result = 10 | xpr::map(nv::Plus{}, xpr::iota(3));

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
    EXPECT_EQ(result[2], 12);
}

TEST(map, xpr_vector_scalar)
{
    vi32 result = xpr::iota(3) | xpr::map(nv::Plus{}, 10);

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
    EXPECT_EQ(result[2], 12);
}

TEST(map, xpr_vector_vector)
{
    vi32 result = xpr::iota(3) | xpr::map(nv::Plus{}, nv::reverse(nv::iota(3)));

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 2);
}

}
