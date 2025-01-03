#include <gtest/gtest.h>
#include <functional>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/functional.hpp"
#include "../../src/pipeline/map.hpp"
#include "../../src/pipeline/reverse.hpp"

namespace {

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
