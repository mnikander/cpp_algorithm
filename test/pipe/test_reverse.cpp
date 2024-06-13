#include <gtest/gtest.h>
#include "../../src/pipe/reverse.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(pipe, reverse)
{
    vi32 data   = {0, 1, 2};
    vi32 result = data | xpr::reverse();
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 0);
}

}
