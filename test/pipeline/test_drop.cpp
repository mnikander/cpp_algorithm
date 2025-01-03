#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/drop.hpp"
#include "../../src/pipeline/iota.hpp"

namespace {

TEST(drop, xpr)
{
    vi32 result = nv::iota(5) | xpr::drop(2);
    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 4);
}

TEST(drop_last, xpr)
{
    vi32 result = nv::iota(5) | xpr::drop_last(2);
    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
}

}
