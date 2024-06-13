#include <gtest/gtest.h>
#include "../../src/naive/iota.hpp"
#include "../../src/naive/gather.hpp"
#include "../../src/naive/scatter.hpp"
#include "../../src/naive/size.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(scatter, nothing)
{
    vi32 nothing = iota(0);
    vi32 result  = scatter(nothing, nothing);
    EXPECT_EQ(size(result), 0);
}

TEST(scatter, no_op)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vc8 result = scatter(alphabet, iota(5));

    EXPECT_EQ(result[0], 'A');
    EXPECT_EQ(result[1], 'B');
    EXPECT_EQ(result[2], 'C');
    EXPECT_EQ(result[3], 'D');
    EXPECT_EQ(result[4], 'E');
}

TEST(scatter, abcde)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vi32 order{2, 0, 1, 4, 3};
    vc8 result = scatter(alphabet, order);

    EXPECT_EQ(result[0], 'B');
    EXPECT_EQ(result[1], 'C');
    EXPECT_EQ(result[2], 'A');
    EXPECT_EQ(result[3], 'E');
    EXPECT_EQ(result[4], 'D');

    vc8 restored = scatter(result, {1, 2, 0, 4, 3});

    EXPECT_EQ(restored[0], 'A');
    EXPECT_EQ(restored[1], 'B');
    EXPECT_EQ(restored[2], 'C');
    EXPECT_EQ(restored[3], 'D');
    EXPECT_EQ(restored[4], 'E');
}

TEST(scatter, gather)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vi32 order{2, 0, 1, 4, 3};
    vc8 intermediate = scatter(alphabet, order);
    vc8 result       = gather(intermediate, order);

    EXPECT_EQ(result[0], 'A');
    EXPECT_EQ(result[1], 'B');
    EXPECT_EQ(result[2], 'C');
    EXPECT_EQ(result[3], 'D');
    EXPECT_EQ(result[4], 'E');
}

}