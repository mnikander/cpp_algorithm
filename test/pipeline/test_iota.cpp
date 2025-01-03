#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"

namespace {

TEST(iota, xpr)
{
    vi32 result = xpr::iota(3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
}

}
