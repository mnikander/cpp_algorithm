#include <gtest/gtest.h>
#include "../src/meta/global_datatypes.hpp"
#include "../src/repeat.hpp"
#include "../src/size.hpp"

namespace {

TEST(repeat, nothing)
{
    vi32 result = nv::repeat(42, 0);
    EXPECT_EQ(size(result), 0);
}

TEST(repeat, twice)
{
    vi32 result = nv::repeat(42, 2);
    EXPECT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 42);
}

TEST(repeat, xpr)
{
    vi32 result = 42 | xpr::repeat(2);
    EXPECT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 42);
    EXPECT_EQ(result[1], 42);
}

}
