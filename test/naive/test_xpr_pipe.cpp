#include <gtest/gtest.h>
#include "../../src/naive/size.hpp"
#include "../../src/naive/reverse.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(pipe, size_without_pipe)
{
    vi32 data        = {};
    const xpr::size s = xpr::size();
    int result       = s(data);
    EXPECT_EQ(result, 0);
}

TEST(pipe, expicit_operator_call)
{
    vi32 data  = {};
    i32 result = xpr::operator|(data, xpr::size());
    EXPECT_EQ(result, 0);
}

TEST(pipe, normal_use)
{
    vi32 data  = {0};
    i32 result = data | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(pipe, inline_vector_construction)
{
    i32 result = vi32{0} | xpr::size();
    EXPECT_EQ(result, 1);
}

TEST(pipe, vector_valued_result)
{
    vi32 data   = {0, 1, 2};
    vi32 result = data | xpr::reverse();
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 0);
}

}
