#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/size.hpp"

namespace {

TEST(size, scalar)
{
    i32 data   = 42;
    i32 result = nv::size(data);
    EXPECT_EQ(result, 1);
}

TEST(size, vector)
{
    vi32 data  = {42};
    i32 result = nv::size(data);
    EXPECT_EQ(result, 1);
}

TEST(size, vector_empty)
{
    vi32 data  = {};
    i32 result = nv::size(data);
    EXPECT_EQ(result, 0);
}

}
