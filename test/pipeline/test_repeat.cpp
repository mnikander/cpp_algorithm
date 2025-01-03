#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/repeat.hpp"
#include "../../src/pipeline/size.hpp"

namespace {

TEST(repeat, xpr)
{
    vi32 result = 42 | xpr::repeat(2);
    EXPECT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 42);
}

}
