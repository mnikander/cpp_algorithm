#include <gtest/gtest.h>
#include "../../src/naive/iota.hpp"
#include "../../src/naive/gather.hpp"
#include "../../src/naive/scatter.hpp"
#include "../../src/naive/size.hpp"
#include "../../src/common.hpp"

namespace {

TEST(gather, nothing)
{
    vi32 nothing = nv::iota(0);
    vi32 result  = nv::gather(nothing, nothing);
    EXPECT_EQ(size(result), 0);
}

TEST(gather, no_op)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vc8 result = nv::gather(alphabet, nv::iota(5));

    EXPECT_EQ(result[0], 'A');
    EXPECT_EQ(result[1], 'B');
    EXPECT_EQ(result[2], 'C');
    EXPECT_EQ(result[3], 'D');
    EXPECT_EQ(result[4], 'E');
}

TEST(gather, abcde)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vi32 order{2, 0, 1, 4, 3};
    vc8 result = nv::gather(alphabet, order);

    EXPECT_EQ(result[0], 'C');
    EXPECT_EQ(result[1], 'A');
    EXPECT_EQ(result[2], 'B');
    EXPECT_EQ(result[3], 'E');
    EXPECT_EQ(result[4], 'D');

    vc8 restored = nv::gather(result, {1, 2, 0, 4, 3});

    EXPECT_EQ(restored[0], 'A');
    EXPECT_EQ(restored[1], 'B');
    EXPECT_EQ(restored[2], 'C');
    EXPECT_EQ(restored[3], 'D');
    EXPECT_EQ(restored[4], 'E');
}

TEST(gather, scatter)
{
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vi32 order{2, 0, 1, 4, 3};
    vc8 intermediate = nv::gather(alphabet, order);
    vc8 result       = nv::scatter(intermediate, order);

    EXPECT_EQ(result[0], 'A');
    EXPECT_EQ(result[1], 'B');
    EXPECT_EQ(result[2], 'C');
    EXPECT_EQ(result[3], 'D');
    EXPECT_EQ(result[4], 'E');
}

}
