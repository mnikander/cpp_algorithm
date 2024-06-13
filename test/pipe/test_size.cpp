#include <gtest/gtest.h>
#include "../../src/pipe/size.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(pipe_size, without_pipe)
{
    vi32 data        = {};
    const pn::Size s = pn::size();
    int result       = s(data);
    EXPECT_EQ(result, 0);
}

TEST(pipe_size, expicit_operator_call)
{
    vi32 data  = {};
    i32 result = pn::operator|(data, pn::size());
    EXPECT_EQ(result, 0);
}

TEST(pipe_size, none)
{
    vi32 data  = {};
    i32 result = data | pn::size();
    EXPECT_EQ(result, 0);
}

}
