#include <gtest/gtest.h>
#include "../../src/naive/repeat.hpp"
#include "../../src/datatype_aliases.hpp"

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

}
