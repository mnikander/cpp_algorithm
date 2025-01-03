#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/reverse.hpp"

namespace {

TEST(reverse, xpr)
{
    vi32 data   = {0, 1, 2};
    vi32 result = data | xpr::reverse();
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 0);
}

}
