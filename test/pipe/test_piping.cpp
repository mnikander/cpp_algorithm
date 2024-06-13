#include <gtest/gtest.h>
#include "../../src/pipe/size.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(pipe, size_without_pipe)
{
    vi32 data        = {};
    const pn::Size s = pn::size();
    int result       = s(data);
    EXPECT_EQ(result, 0);
}

TEST(pipe, expicit_operator_call)
{
    vi32 data  = {};
    i32 result = pn::operator|(data, pn::size());
    EXPECT_EQ(result, 0);
}

TEST(pipe, normal_use)
{
    vi32 data  = {0};
    i32 result = data | pn::size();
    EXPECT_EQ(result, 1);
}

TEST(pipe, inline_vector_construction)
{
    i32 result = vi32{0} | pn::size();
    EXPECT_EQ(result, 1);
}

}
