#include <gtest/gtest.h>
#include "../../src/naive/arithmetic.hpp"
#include "../../src/naive/common.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/repeat.hpp"

namespace naive {

TEST(plus, int_int)
{
    i32 result = plus(2, 5);
    EXPECT_EQ(result, 7);
}

TEST(plus, vector_int)
{
    vi32 vec    = iota(2);
    vi32 result = plus(vec, 40);

    EXPECT_EQ(result.size(), vec.size());
    EXPECT_EQ(result[0], 40);
    EXPECT_EQ(result[1], 41);
}

TEST(plus, int_vector)
{
    vi32 vec    = iota(2);
    vi32 result = plus(40, vec);

    EXPECT_EQ(result.size(), vec.size());
    EXPECT_EQ(result[0], 40);
    EXPECT_EQ(result[1], 41);
}

TEST(plus, vector_vector)
{
    vi32   left = iota(2);
    vi32  right = repeat(10, 2);
    vi32 result = plus(left, right);

    EXPECT_EQ(result.size(), left.size());
    EXPECT_EQ(result.size(), right.size());
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 11);
}

}
