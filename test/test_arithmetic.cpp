#include <gtest/gtest.h>
#include "../src/arithmetic.hpp"
#include "../src/iota.hpp"
#include "../src/repeat.hpp"
#include "../src/datatype_aliases.hpp"

namespace {

TEST(plus, int_int)
{
    i32 result = nv::plus(2, 5);
    EXPECT_EQ(result, 7);
}

TEST(plus, vector_int)
{
    vi32 vec    = nv::iota(2);
    vi32 result = nv::plus(vec, 40);

    EXPECT_EQ(nv::size(result), 2);
    EXPECT_EQ(result[0], 40);
    EXPECT_EQ(result[1], 41);
}

TEST(plus, int_vector)
{
    vi32 vec    = nv::iota(2);
    vi32 result = nv::plus(40, vec);

    EXPECT_EQ(nv::size(result), 2);
    EXPECT_EQ(result[0], 40);
    EXPECT_EQ(result[1], 41);
}

TEST(plus, vector_vector)
{
    vi32   left = nv::iota(2);
    vi32  right = nv::repeat(10, 2);
    vi32 result = nv::plus(left, right);

    EXPECT_EQ(nv::size(result), 2);
    EXPECT_EQ(nv::size(result), 2);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
}

}
