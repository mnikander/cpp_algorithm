#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/rank.hpp"

namespace {

TEST(rank, xpr)
{
    i32 scalar = 0 | xpr::rank();
    i32 vector = vi32{0} | xpr::rank();
    EXPECT_EQ(scalar, 0);
    EXPECT_EQ(vector, 1);
}

}
