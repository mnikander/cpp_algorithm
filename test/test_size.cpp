#include <gtest/gtest.h>
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

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

TEST(size, xpr_scalar)
{
    i32 result = 42 | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(size, xpr_vector)
{
    i32 result = vi32{0} | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(size, xpr_vector_empty)
{
    i32 result = vi32{} | xpr::size();
    EXPECT_EQ(result, 0);
}

}
